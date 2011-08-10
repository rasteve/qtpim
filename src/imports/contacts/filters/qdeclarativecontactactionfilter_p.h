/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef QDECLARATIVECONTACTACTIONFILTER_H
#define QDECLARATIVECONTACTACTIONFILTER_H

#include "qdeclarativecontactfilter_p.h"
#include "qcontactactionfilter.h"

QTPIM_BEGIN_NAMESPACE

class QDeclarativeContactActionFilter : public QDeclarativeContactFilter
{
    Q_OBJECT
    Q_PROPERTY(QString actionName READ actionName WRITE setActionName NOTIFY valueChanged())
public:
    QDeclarativeContactActionFilter(QObject* parent=0)
        :QDeclarativeContactFilter(parent)
    {
        connect(this, SIGNAL(valueChanged()), SIGNAL(filterChanged()));
    }
    void setActionName(const QString& action)
    {
        if (action != d.actionName()) {
            d.setActionName(action);
            emit valueChanged();
        }
    }

    QString actionName() const
    {
        return d.actionName();
    }
    QContactFilter filter() const
    {
        return d;
    }

signals:
    void valueChanged();

private:
    QContactActionFilter d;
};

#include "moc_qdeclarativecontactactionfilter_p.cpp"

QTPIM_END_NAMESPACE

QML_DECLARE_TYPE(QTPIM_PREPEND_NAMESPACE(QDeclarativeContactActionFilter))

#endif
