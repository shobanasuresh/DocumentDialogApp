#ifndef __FileInfo__
#define __FileInfo__

#include <QObject>
#include <QVariant>
#include <QFile>
#include <QUrl>

class FileInfoPrivate;

class FileInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString absoluteFilePath READ absoluteFilePath NOTIFY fileInfoChanged)
    Q_PROPERTY(QString absolutePath READ absolutePath NOTIFY fileInfoChanged)
    Q_PROPERTY(bool exists READ exists NOTIFY fileInfoChanged)
    Q_PROPERTY(QString displayName READ displayName NOTIFY fileInfoChanged)
    Q_PROPERTY(QString fileName READ fileName NOTIFY fileInfoChanged)
    Q_PROPERTY(QString filePath READ filePath NOTIFY fileInfoChanged)
    Q_PROPERTY(qint64 size READ size NOTIFY fileInfoChanged)
    Q_PROPERTY(QVariant url READ url WRITE setUrl NOTIFY fileInfoChanged)
    Q_PROPERTY(QVariant extra READ extra NOTIFY fileInfoChanged)

public:
    FileInfo(QObject* parent = nullptr);
    ~FileInfo();

    Q_INVOKABLE QVariant dataUri() const;
    Q_INVOKABLE QByteArray readAll() const;

signals:
    void fileInfoChanged();

protected:
    QString absoluteFilePath() const;
    QString absolutePath() const;
    QString baseName() const;
    bool exists() const;
    QString displayName() const;
    QString fileName() const;
    QString filePath() const;
    qint64 size() const;
    QVariant extra() const;

    QVariant url() const;
    void setUrl(const QVariant& url);

    FileInfoPrivate* m_FileInfoPrivate;
};

#endif