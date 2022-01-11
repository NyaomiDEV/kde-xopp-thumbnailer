#ifndef XOPP_THUMBNAILER_H
#define XOPP_THUMBNAILER_H

#include <QObject>
#include <kio/thumbcreator.h>

class XoppThumbnailer : public QObject, public ThumbCreator {
    Q_OBJECT
public:
    XoppThumbnailer();
    virtual ~XoppThumbnailer();
    virtual bool create(const QString& path, int width, int height, QImage& img) override;
    virtual Flags flags() const override;
};

#endif // XOPP_THUMBNAILER_H
