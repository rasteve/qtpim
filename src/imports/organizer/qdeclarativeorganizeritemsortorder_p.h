/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Mobility Components.
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

#ifndef QDECLARATIVEORGANIZERITEMSORTORDER_H
#define QDECLARATIVEORGANIZERITEMSORTORDER_H

#include "qdeclarativeorganizeritemdetail_p.h"
#include <qorganizeritemsortorder.h>
#include <QtDeclarative/qdeclarative.h>
#include <QtDeclarative/qdeclarativeparserstatus.h>

QTORGANIZER_BEGIN_NAMESPACE

class QDeclarativeOrganizerItemSortOrder : public QObject, public QDeclarativeParserStatus
{
    Q_OBJECT
    Q_PROPERTY(QVariant detail READ detail WRITE setDetail NOTIFY sortOrderChanged)
    Q_PROPERTY(QVariant field READ field WRITE setField NOTIFY sortOrderChanged)
    Q_PROPERTY(BlankPolicy blankPolicy READ blankPolicy WRITE setBlankPolicy NOTIFY sortOrderChanged)
    Q_PROPERTY(Qt::SortOrder direction READ direction WRITE setDirection NOTIFY sortOrderChanged)
    Q_PROPERTY(Qt::CaseSensitivity sensitivity READ caseSensitivity WRITE setCaseSensitivity NOTIFY sortOrderChanged)
    Q_INTERFACES(QDeclarativeParserStatus)
    Q_ENUMS(BlankPolicy)

public:
    enum BlankPolicy {
        BlanksFirst = QOrganizerItemSortOrder::BlanksFirst,
        BlanksLast = QOrganizerItemSortOrder::BlanksLast
    };

    QDeclarativeOrganizerItemSortOrder(QObject *parent = 0);

    void setDetail(const QVariant &detail);
    QVariant detail() const;

    void setField(const QVariant &field);
    QVariant field() const;

    void setBlankPolicy(BlankPolicy policy);
    BlankPolicy blankPolicy() const;

    void setDirection(Qt::SortOrder newDirection);
    Qt::SortOrder direction() const;

    void setCaseSensitivity(Qt::CaseSensitivity newSensitivity);
    Qt::CaseSensitivity caseSensitivity() const;

    // from QDeclarativeParserStatus
    void classBegin();
    void componentComplete();

    // used by organizer model
    QOrganizerItemSortOrder sortOrder();

Q_SIGNALS:
    void sortOrderChanged();

private:
    void setSortOrder(const QOrganizerItemSortOrder &sortOrder);

    QVariant m_field;
    QVariant m_detail;
    QOrganizerItemSortOrder d;
};

QTORGANIZER_END_NAMESPACE

QML_DECLARE_TYPE(QTORGANIZER_PREPEND_NAMESPACE(QDeclarativeOrganizerItemSortOrder))

#endif // QDECLARATIVEORGANIZERITEMSORTORDER_H
