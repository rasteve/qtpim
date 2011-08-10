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

#ifndef QORGANIZERITEMDETAILFILTER_P_H
#define QORGANIZERITEMDETAILFILTER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qorganizeritemfilter_p.h"
#include "qorganizeritemfilter.h"

#include <QString>
#include <QVariant>

QTPIM_BEGIN_NAMESPACE

class QOrganizerItemDetailFilterPrivate : public QOrganizerItemFilterPrivate
{
public:
    QOrganizerItemDetailFilterPrivate()
        : QOrganizerItemFilterPrivate(),
        m_flags(0)
    {
    }

    QOrganizerItemDetailFilterPrivate(const QOrganizerItemDetailFilterPrivate& other)
        : QOrganizerItemFilterPrivate(other),
        m_defId(other.m_defId),
        m_fieldId(other.m_fieldId),
        m_exactValue(other.m_exactValue),
        m_flags(other.m_flags)
    {
    }

    virtual bool compare(const QOrganizerItemFilterPrivate* other) const
    {
        const QOrganizerItemDetailFilterPrivate *od = static_cast<const QOrganizerItemDetailFilterPrivate*>(other);
        if (m_defId != od->m_defId)
            return false;
        if (m_fieldId != od->m_fieldId)
            return false;
        if (m_exactValue != od->m_exactValue)
            return false;
        if (m_flags != od->m_flags)
            return false;
        return true;
    }

    QDataStream& outputToStream(QDataStream& stream, quint8 formatVersion) const
    {
        if (formatVersion == 1) {
            stream << m_defId << m_fieldId << m_exactValue << static_cast<quint32>(m_flags);
        }
        return stream;
    }

    QDataStream& inputFromStream(QDataStream& stream, quint8 formatVersion)
    {
        if (formatVersion == 1) {
            quint32 flags;
            stream >> m_defId >> m_fieldId >> m_exactValue >> flags;
            m_flags = static_cast<QOrganizerItemFilter::MatchFlags>(flags);
        }
        return stream;
    }

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const
    {
        dbg.nospace() << "QOrganizerItemDetailFilter(";
        dbg.nospace() << "detailDefinitionName=";
        dbg.nospace() << m_defId;
        dbg.nospace() << ",";
        dbg.nospace() << "detailFieldName=";
        dbg.nospace() << m_fieldId;
        dbg.nospace() << ",";
        dbg.nospace() << "value=";
        dbg.nospace() << m_exactValue;
        dbg.nospace() << ",";
        dbg.nospace() << "matchFlags=";
        dbg.nospace() << static_cast<quint32>(m_flags);
        dbg.nospace() << ")";
        return dbg.maybeSpace();
    }
#endif

    Q_IMPLEMENT_ORGANIZERITEMFILTER_VIRTUALCTORS(QOrganizerItemDetailFilter, QOrganizerItemFilter::OrganizerItemDetailFilter)

    QString m_defId;
    QString m_fieldId;
    QVariant m_exactValue;
    QOrganizerItemFilter::MatchFlags m_flags;
};

QTPIM_END_NAMESPACE

#endif
