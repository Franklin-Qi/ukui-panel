/*
 * Copyright (C) 2019 Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
 *
 */
#include "ukuitraystrage.h"

storageBarStatus status;
/*收纳栏*/
UKUIStorageFrame::UKUIStorageFrame(QWidget *parent):
    QWidget(parent, Qt::Popup)
{
    installEventFilter(this);
    setLayout(new UKUi::GridLayout(this));
    dynamic_cast<UKUi::GridLayout*>(layout())->setRowCount(1);
    dynamic_cast<UKUi::GridLayout*>(layout())->setColumnCount(1);
    setMinimumHeight(0);
    setMinimumWidth(0);
    setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    /*
     * @brief setWindowFlags
     *
     * 冲突的窗口属性 这里本应使用Popup窗口属性，但是popup的属性与托盘有冲突
     * 会使得点击事件无法生效
     *
     * 备选方案是使用QToolTip 这导致了无法进入事件过滤来检测活动窗口的变化
     *
     * Qt::WindowStaysOnTopHint | Qt::Tool | Qt::FramelessWindowHint
     * 这三个参数分别代表 设置窗体一直置顶，并且不会抢焦点 | 工具窗口 |设置窗体无边框，不可拖动拖拽拉伸
     *
     * 但是在某些情况下会出现在任务啦上依然会显示窗口，因此加入新的属性 X11BypassWindowManagerHint
     */
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Tool | Qt::FramelessWindowHint| Qt::X11BypassWindowManagerHint);
    _NET_SYSTEM_TRAY_OPCODE = XfitMan::atom("_NET_SYSTEM_TRAY_OPCODE");

}

UKUIStorageFrame::~UKUIStorageFrame(){
}

/*
 * 事件过滤，检测鼠标点击外部活动区域则收回收纳栏
*/
bool UKUIStorageFrame::eventFilter(QObject *obj, QEvent *event)
{
    //    Q_UNUSED(obj);
    //    Q_UNUSED(event);

    if (obj == this)
    {
        /*　　　//绑定快捷键
        if (event->type() == QEvent::KeyPress)
           {
               //将QEvent对象转换为真正的QKeyEvent对象
               QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
               if (keyEvent->key() == Qt::Key_Tab)
               {
                   this->hide();
                   status=ST_HIDE;
                   return true;
               }
           }
           */

        /* 这里处理的鼠标左键和右键事件只是TrayIcon 区域，图标之外的部分
         * 与在trayIcon类中处理mousePressEvent是一样的
　　　　　*/
        if (event->type() == QEvent::MouseButtonPress)
           {
               //将QEvent对象转换为真正的QKeyEvent对象
               QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
               if (mouseEvent->button() == Qt::LeftButton)
               {
                   this->hide();
                   status=ST_HIDE;
                   return true;
               }
               else if(mouseEvent->button() == Qt::RightButton)
               {
                   return true;
               }
           }
        else if(event->type() == QEvent::ContextMenu)
        {
            return false;
        }
        else if (event->type() == QEvent::WindowDeactivate &&status==ST_SHOW)
        {
            //qDebug()<<"激活外部窗口";
            this->hide();
            status=ST_HIDE;
            return true;
        } else if (event->type() == QEvent::StyleChange) {
        }

    }

    if (!isActiveWindow())
    {
        activateWindow();
    }
    return false;
}

void UKUIStorageFrame::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    p.setBrush(QBrush(QColor(0x13,0x14,0x14,0x4d)));
    p.setPen(Qt::NoPen);
    p.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
    QPainterPath path;
    p.drawRoundedRect(opt.rect,6,6);
    path.addRoundedRect(opt.rect,6,6);
    setProperty("blurRegion",QRegion(path.toFillPolygon().toPolygon()));
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

UKUiStorageWidget::UKUiStorageWidget(){
    setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
}

UKUiStorageWidget::~UKUiStorageWidget(){
}

void UKUiStorageWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    p.setBrush(QBrush(QColor(0x13,0x14,0x14,0x4d)));
    p.setPen(Qt::NoPen);
    p.setRenderHint(QPainter::Antialiasing);
    p.drawRoundedRect(opt.rect,6,6);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
