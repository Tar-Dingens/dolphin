/* This file is part of the KDE projects
   Copyright (C) 2000 David Faure <faure@kde.org>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
    General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef __konqdirpart_h
#define __konqdirpart_h

#include <qstring.h>
#include <kparts/part.h>

class KonqPropsView;
class QScrollView;

class KonqDirPart: public KParts::ReadOnlyPart
{
  // TODO get rid of this
  friend class IconViewBrowserExtension; // to access m_pProps
  friend class ListViewBrowserExtension;
  Q_OBJECT
public:
    KonqDirPart( QObject *parent, const char *name );
    virtual ~KonqDirPart();

    QScrollView * scrollWidget();

    virtual void saveState( QDataStream &stream );
    virtual void restoreState( QDataStream &stream );

    QString nameFilter() const { return m_nameFilter; }

public slots:
    void slotBackgroundColor();
    void slotBackgroundImage();

protected:
    QString m_nameFilter;
    /**
     * View properties
     */
    KonqPropsView * m_pProps;
};

#endif
