#ifndef MAIN_H
#define MAIN_H

#include <QCoreApplication>
#include <QTextStream>
#include <QDir>
#include <QtDebug>

#include <libzippp/libzippp.h>

#include <QtXlsx>
//#include "xlsxdocument.h"
//#include "xlsxchartsheet.h"
//#include "xlsxcellrange.h"
//#include "xlsxchart.h"
//#include "xlsxrichstring.h"
//#include "xlsxworkbook.h"


const QString out_xlsx_fname = "out.xlsx";

void get_file_names(QString *dir_path_name, QVector<QString> *file_names,
                    bool *ok, QString *err_name);
QString read_from_archive(QString fname);

#endif // MAIN_H
