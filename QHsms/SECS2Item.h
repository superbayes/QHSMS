#ifndef SECS2ITEM_H
#define SECS2ITEM_H
#include<cstdint>
#include <QByteArray>
#include <QVector>
#ifdef _WIN64
typedef int64_t		i8;
typedef int8_t		i1;
typedef int16_t		i2;
typedef int32_t		i4;
typedef uint64_t	u8;
typedef uint64_t	U8;
typedef uint8_t		u1;
typedef uint8_t		U1;
typedef uint16_t	u2;
typedef uint16_t	U2;
typedef uint32_t	u4;
typedef uint32_t	U4;
typedef double		f8;
typedef float		f4;
typedef bool		sboolean;
#endif

class SECS2Item
{
public:
    SECS2Item();
    SECS2Item(QString name) {m_name = name;}
    SECS2Item(QString name,QString itemContent);
    SECS2Item(QString name, U4 itemContent);
    SECS2Item(char str[]) {m_name = QString(str);}
    SECS2Item(const SECS2Item &x);
    enum ItemFormatCode{IFC_LIST = 000 << 2,
                        IFC_BINARY = 010 << 2,
                        IFC_BOOLEAN = 011 << 2,
                        IFC_ASCII = 020 << 2,
                        IFC_JIS8 = 021 << 2,
                        IFC_CHAR16 = 022 << 2,
                        IFC_INT8 = 031 << 2,
                        IFC_INT16 = 032 << 2,
                        IFC_INT32 = 034 << 2,
                        IFC_INT64 = 030 << 2,
                        IFC_FLOAT = 044 << 2,
                        IFC_DOUBLE = 040 << 2,
                        IFC_UINT8 = 051 << 2,
                        IFC_UINT16 = 052 << 2,
                        IFC_UINT32 = 054 << 2,
                        IFC_UINT64 = 050 << 2
                        };

    /**
     * @brief isList 判断这个 Item 是不是一个 LIST
     * @return
     */
    bool isList() const;
    bool isEmptyList() const {return isList() && m_itemBody.isEmpty();}
    /**
     * @brief loadFromByteArray 从一个 QByteArray 中构造这个 Item
     * @param array
     * @return 成功则返回正数，这个正数表明用了 array 中多少个字节。
     *         如果不成功返回负数， -1 表示 array 字节数不够， -2 表示解析 Header 失败
     */
    int loadFromByteArray(const QByteArray &array);

    /**
     * @brief emptyList 返回一个空的 LIST。（有些命令的回复是一个空 LIST）
     * @return
     */
    static SECS2Item emptyList();

    /**
     * @brief merge 将SECS2ItemList 转变为一个新的SECS2Item
     * @return SECS2Item
     */
    static SECS2Item SECS2ItemList2SECS2Item(SECS2Item* SECS2Item,int length);
    static SECS2Item mergeSECS2Item(SECS2Item item1,SECS2Item item2);
    static SECS2Item mergeSECS2Item(SECS2Item* itemList1,int len1,SECS2Item* itemList2,int len2);

    /**
     * @brief merge 将SECS2ItemList与this合并为一个
     * @return SECS2Item
     */
    SECS2Item merge(SECS2Item* SECS2Item,int length);

    QByteArray itemData() const { return m_itemDataAll;}
    QString stringLog(QString leadingStr) const;
    QString toXml(QString leadingStr) const;// 没有写完
    void setASCII(const char *str);
    void setASCII(QString str);
    void setBoolean(const bool x[], int N);
    void setBinary(const QByteArray &x);
    void setJIS8(const char * str);
    void setInt8(const int8_t x[], int N);
    void setInt8(const QVector<int8_t> &x);
    void setInt16(const int16_t x[], int N);
    void setInt32(const int32_t x[], int N);
    void setInt64(const int64_t x[], int N);
    void setUInt8(const uint8_t x[], int N);
    void setUInt8(const uint8_t x);
    void setUInt16(const uint16_t x[], int N);
    void setUInt32(const uint32_t x[], int N);
    void setUInt32(const uint32_t x);
    void setUInt64(const uint64_t x[], int N);
    void setItems(const SECS2Item x[], int N);
    void setItems(const QVector<SECS2Item> &x);
    void setFloat(const float x[], int N);
    void setDouble(const double x[], int N);

    /// 以下的函数获取 Item 里面的数据
    ItemFormatCode format() const {return m_format;}
    QVector<bool> toBoolean(bool *ok = nullptr) const;
    QString toASCII(bool *ok = nullptr) const;
    QByteArray toJIS8(bool *ok = nullptr) const;
    QByteArray toBinary(bool *ok = nullptr) const;
    QVector<int8_t> toInt8(bool *ok = nullptr) const;
    QVector<int16_t> toInt16(bool *ok = nullptr) const;
    QVector<int32_t> toInt32(bool *ok = nullptr) const;
    QVector<int64_t> toInt64(bool *ok = nullptr)const;
    QVector<uint8_t> toUInt8(bool *ok = nullptr)const;
    QVector<uint16_t> toUInt16(bool *ok = nullptr)const;
    QVector<uint32_t> toUInt32(bool *ok = nullptr)const;
    QVector<uint64_t> toUInt64(bool *ok = nullptr)const;
    QVector<float> toFloat(bool *ok = nullptr) const;
    QVector<double> toDouble(bool *ok = nullptr) const;
    QVector<SECS2Item> toItems(bool *ok = nullptr)const;
    int bytes()const {return m_bytes;}
    int size()const {return m_itemDataAll.size();}
private:

    /**
     * @brief buildItemHeader 根据具体的数据类型构造 Item Header
     * @return 返回 Item Header 有多少个字节
     */
    int buildItemHeader();
    QString int8String(QString leadingstr) const;
    QString int16String(QString leadingstr) const;
    QString int32String(QString leadingstr) const;
    QString int64String(QString leadingstr) const;
    QString uint8String(QString leadingstr) const;
    QString uint16String(QString leadingstr) const;
    QString uint32String(QString leadingstr) const;
    QString uint64String(QString leadingstr) const;
    QString floatString(QString leadingstr) const;
    QString doubleString(QString leadingstr) const;
    QString boolString(QString leadingstr) const;
    QString binaryString(QString leadingstr) const;
    QString ASCIIString(QString leadingstr) const;
    enum ItemFormatCode m_format;
    int m_bytes;
    QByteArray m_itemHeader;
    QByteArray m_itemBody;
    QByteArray m_itemDataAll;
    QVector<SECS2Item> m_itemVector;
    QString m_name;
};

#endif // SECS2ITEM_H
