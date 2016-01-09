/* ============================================================
* ImageFinder plugin for QupZilla
* Copyright (C) 2016 Vladislav Tronko <innermous@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#include "imagefinderplugin.h"
#include "imagefindersettings.h"
#include "browserwindow.h"
#include "webview.h"
#include "pluginproxy.h"
#include "mainapplication.h"
#include "webhittestresult.h"

#include <QMenu>
#include <QTranslator>
#include <QPushButton>

ImageFinderPlugin::ImageFinderPlugin()
    : QObject()
    , m_view(0)
{
}

PluginSpec ImageFinderPlugin::pluginSpec()
{
    PluginSpec spec;
    spec.name = "ImageFinder";
    spec.info = "Image Finder Plugin";
    spec.description = "Provides context menu with reverse image search engine support";
    spec.version = "0.1.0";
    spec.author = "Vladislav Tronko <innermous@gmail.com>";
    spec.icon = QPixmap(":/imgfinder/data/icon.png");
    spec.hasSettings = true;

    return spec;
}

void ImageFinderPlugin::init(InitState state, const QString &settingsPath)
{
    qDebug() << __FUNCTION__ << "called";

    Q_UNUSED(state);

    QZ_REGISTER_EVENT_HANDLER(PluginProxy::MousePressHandler);
    QZ_REGISTER_EVENT_HANDLER(PluginProxy::KeyPressHandler);
}

void ImageFinderPlugin::unload()
{

}

bool ImageFinderPlugin::testPlugin()
{
    // Require the version that the plugin was built with
    return (Qz::VERSION == QLatin1String(QUPZILLA_VERSION));
}

QTranslator* ImageFinderPlugin::getTranslator(const QString &locale)
{
    QTranslator* translator = new QTranslator(this);
    translator->load(locale, ":/autoscroll/locale/");
    return translator;
}

void ImageFinderPlugin::showSettings(QWidget *parent)
{

}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(ImageFinder, ImageFinderPlugin)
#endif
