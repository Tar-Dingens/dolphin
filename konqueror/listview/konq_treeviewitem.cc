/* This file is part of the KDE project
   Copyright (C) 1998, 1999 Torben Weis <weis@kde.org>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#include "konq_propsview.h"
#include "konq_treeviewitem.h"
#include "konq_treeviewwidget.h"
#include <konqfileitem.h>
#include <kio/job.h>
#include <kio/global.h>
#include <klocale.h>
#include <assert.h>
#include <stdio.h>


/**************************************************************
 *
 * KonqListViewDir
 *
 **************************************************************/

KonqListViewDir::KonqListViewDir( KonqTreeViewWidget *_parent, KonqFileItem* _fileitem )
:KonqListViewItem( _parent, _fileitem )
,m_treeViewWidget(_parent)
{
  m_treeViewWidget->addSubDir( _fileitem->url(), this );

  m_bComplete = false;
}

KonqListViewDir::KonqListViewDir( KonqTreeViewWidget *_treeview, KonqListViewDir * _parent, KonqFileItem* _fileitem )
:KonqListViewItem(_treeview,_parent,_fileitem)
,m_treeViewWidget(_treeview)
{
  m_treeViewWidget->addSubDir( _fileitem->url(), this );

  m_bComplete = false;
}

KonqListViewDir::~KonqListViewDir()
{
  if ( m_treeViewWidget )
    m_treeViewWidget->removeSubDir( m_fileitem->url() );
}

void KonqListViewDir::setup()
{
  setExpandable( true );
  QListViewItem::setup();
}

void KonqListViewDir::setOpen( bool _open )
{
  if ( _open && !m_bComplete ) // complete it before opening
    m_treeViewWidget->openSubFolder( m_fileitem->url(), this );

  QListViewItem::setOpen( _open );
}

QString KonqListViewDir::url( int _trailing )
{
  return m_fileitem->url().url( _trailing );
}

