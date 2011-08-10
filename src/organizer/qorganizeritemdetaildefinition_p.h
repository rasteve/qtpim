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


#ifndef QORGANIZERITEMDETAILDEFINITION_P_H
#define QORGANIZERITEMDETAILDEFINITION_P_H

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

#include "qorganizeritemdetaildefinition.h"

#include <QSharedData>
#include <QMap>
#include <QString>
#include <QVariant>

QTPIM_BEGIN_NAMESPACE

class QOrganizerItemDetailDefinitionData : public QSharedData
{
public:
    QOrganizerItemDetailDefinitionData()
        : m_unique(false)
    {
    }

    QOrganizerItemDetailDefinitionData(const QOrganizerItemDetailDefinitionData& other)
        : QSharedData(other),
        m_name(other.m_name),
        m_unique(other.m_unique),
        m_fields(other.m_fields)
    {
    }

    ~QOrganizerItemDetailDefinitionData() {}

    QString m_name;
    bool m_unique;
    QMap<QString, QOrganizerItemDetailFieldDefinition> m_fields;
};

QTPIM_END_NAMESPACE

#endif
