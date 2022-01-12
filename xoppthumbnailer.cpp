#include "xoppthumbnailer.h"

#include <QDir>
#include <QFile>
#include <QImage>
#include <QProcess>
#include <QStandardPaths>
#include <QCryptographicHash>

extern "C" {
    Q_DECL_EXPORT ThumbCreator *new_creator() {
        return new XoppThumbnailer();
    }
}

XoppThumbnailer::XoppThumbnailer(){}

XoppThumbnailer::~XoppThumbnailer(){}

bool XoppThumbnailer::create(const QString& path, int width, int height, QImage& img){
    QString cacheDirectory((QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + "/thumbnails/xoppthumbnailer/"));
    QString md5Hash = QString(QCryptographicHash::hash((path.toUtf8()), QCryptographicHash::Md5).toHex());
    QString thumbnailPath(cacheDirectory + md5Hash + ".png");
    
    QDir directory(cacheDirectory);
    if (!directory.exists())
        directory.mkpath(".");

    QProcess process;
    process.setProcessChannelMode(QProcess::ForwardedChannels);
    process.start("xournalpp", {path, "-i", thumbnailPath, "--export-range", "1", "--export-png-width", QString::number(width)});
    process.waitForFinished();

    if (QFile::exists(thumbnailPath)){
        QFile thumbnailFile(thumbnailPath);
        img = QImage(thumbnailPath).scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        thumbnailFile.remove();
    }

    return !img.isNull();
}

ThumbCreator::Flags XoppThumbnailer::flags() const {    
    return (Flags)(None);
}
