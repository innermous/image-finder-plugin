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
#include "imagefindersettings.h"
#include "ui_imagefindersettings.h"
#include "imagefinder.h"

ImageFinderSettings::ImageFinderSettings(ImageFinder* finder, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ImageFinderSettings)
    , m_finder(finder)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accepted()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close()));
    // (ui)->setEngine ( finder:engine )
}

ImageFinderSettings::~ImageFinderSettings()
{
    delete ui;
}

void ImageFinderSettings::accepted()
{
    // update search engine
    close();
}
