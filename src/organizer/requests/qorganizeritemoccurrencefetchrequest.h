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

#ifndef QORGANIZERITEMOCCURRENCEFETCHREQUEST_H
#define QORGANIZERITEMOCCURRENCEFETCHREQUEST_H

#include "qtorganizerglobal.h"
#include "qorganizerabstractrequest.h"
#include "qorganizeritemsortorder.h"
#include "qorganizeritemfilter.h"
#include "qorganizeritem.h"
#include "qorganizeritemfetchhint.h"

#include <QList>
#include <QStringList>

QTPIM_BEGIN_NAMESPACE

class QOrganizerItemOccurrenceFetchRequestPrivate;
class Q_ORGANIZER_EXPORT QOrganizerItemOccurrenceFetchRequest : public QOrganizerAbstractRequest
{
    Q_OBJECT

public:
    QOrganizerItemOccurrenceFetchRequest(QObject* parent = 0);
    ~QOrganizerItemOccurrenceFetchRequest();

    void setParentItem(const QOrganizerItem& item);
    void setStartDate(const QDateTime& date);
    void setEndDate(const QDateTime& date);
    void setMaxOccurrences(int maxCount);
    void setFetchHint(const QOrganizerItemFetchHint& hint);

    QOrganizerItem parentItem() const;
    QDateTime startDate() const;
    QDateTime endDate() const;
    int maxOccurrences() const;
    QOrganizerItemFetchHint fetchHint() const;

    /* Results */
    QList<QOrganizerItem> itemOccurrences() const;

private:
    Q_DISABLE_COPY(QOrganizerItemOccurrenceFetchRequest)
    friend class QOrganizerManagerEngine;
    Q_DECLARE_PRIVATE_D(d_ptr, QOrganizerItemOccurrenceFetchRequest)
};

QTPIM_END_NAMESPACE

#endif
