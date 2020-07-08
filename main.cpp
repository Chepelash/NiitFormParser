#include "main.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);
    QTextStream in(stdin);
    QString dir_path_name = "";
    QVector <QString> file_names;
    QString file_text;
    bool ok = true;
    QString err_name = "";

    out << "Write dir name >> ";
    out.flush();
    in.readLineInto(&dir_path_name);
    get_file_names(&dir_path_name, &file_names, &ok, &err_name);
    if(!ok){
        out << "Error. " << err_name << Qt::endl;
        a.exit(0);
    }
    QDir cur_dir(".", out_xlsx_fname, QDir::Name, QDir::Files);
    QFileInfoList list = cur_dir.entryInfoList();
    if(list.size() != 0){
        // remove xlsx
        cur_dir.remove(list.at(0).fileName());
    }
    QXlsx::Document xlsxW;
    xlsxW.write("A2", "Hell2o");
    xlsxW.saveAs(out_xlsx_fname);

    for(int i = 0; i < file_names.size(); i++){
//        out << file_names.at(i) << Qt::endl;
        file_text = read_from_archive(file_names.at(i));

    }
    a.exit(0);
}


QString read_from_archive(QString fname){
    libzippp::ZipArchive zf(fname.toStdString());//fname.toStdString());
    zf.open(libzippp::ZipArchive::READ_ONLY);
    libzippp::ZipEntry entry = zf.getEntry("word/document.xml");
    QString ftext = QString::fromStdString(entry.readAsText());

    zf.close();

    return ftext;
}

void get_file_names(QString *dir_path_name, QVector<QString> *file_names,
                    bool *ok, QString *err_name){
    QDir dir_path(*dir_path_name, "*.docx", QDir::Name, QDir::Files);
    if(!dir_path.exists()){
        *ok = false;
        *err_name = "Path doesn't exists";
    } else if(dir_path_name->length() == 0){
        *ok = false;
        *err_name = "Entered empty path";
    } else {
        QFileInfoList list = dir_path.entryInfoList();
        if(list.size() == 0){
            *ok = false;
            *err_name = "No docx files in dir";
        } else {
            for(int i = 0; i < list.size(); i++){
                QFileInfo file_info = list.at(i);
                file_names->append(file_info.fileName());
            }
        }
    }
}
