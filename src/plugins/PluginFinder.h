/*
 * Copyright (C) 2021 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef KSNIP_PLUGINFINDER_H
#define KSNIP_PLUGINFINDER_H

#include <QString>
#include <QSharedPointer>
#include <QFileInfo>

#include "IPluginFinder.h"
#include "IPluginLoader.h"
#include "PluginInfo.h"
#include "src/plugins/interfaces/IPluginOcr.h"
#include "src/gui/directoryService/IDirectoryService.h"

class PluginFinder : public IPluginFinder
{
public:
	PluginFinder(const QSharedPointer<IPluginLoader> &loader, const QSharedPointer<IDirectoryService> &directoryService);
	~PluginFinder() = default;
	QList<PluginInfo> find(const QString &path) const override;

private:
	QSharedPointer<IPluginLoader> mLoader;
	QSharedPointer<IDirectoryService> mDirectoryService;

	template<class T>
	QSharedPointer<T> castTo(const QSharedPointer<QObject> &plugin) const;
	QList<PluginInfo> findPluginsInDirectory(const QString &path) const;
};

#endif //KSNIP_PLUGINFINDER_H
