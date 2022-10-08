#include "SECS2Item.h"
#include <QDebug>
SECS2Item::SECS2Item()
{
    m_format = SECS2Item::IFC_LIST;
    m_name = "NoName";
    m_bytes = 0;
    m_itemBody.clear();
    m_itemHeader.clear();
    m_itemDataAll.clear();
    m_itemVector.clear();
}

SECS2Item::SECS2Item(QString name, QString itemContent)
{
    this->m_name = name;
    this->setASCII(itemContent);
}

SECS2Item::SECS2Item(QString name, U4 itemContent)
{
    this->m_name = name;
    const uint32_t x[1] ={itemContent};
    this->setUInt32(x,1);
}

SECS2Item SECS2Item::emptyList()
{
    SECS2Item list;

    list.m_format = SECS2Item::IFC_LIST;
    list.m_bytes = 0;   
    list.buildItemHeader();
    list.m_itemBody.clear();
    return list;
}

SECS2Item SECS2Item::SECS2ItemList2SECS2Item(SECS2Item *SECS2Item, int length)
{
    class SECS2Item tmp;
    tmp.setItems(SECS2Item,length);
    return tmp;
}

SECS2Item SECS2Item::mergeSECS2Item(SECS2Item item1, SECS2Item item2)
{
    SECS2Item tmpList[2],tmp;
    tmpList[0] = item1;
    tmpList[1] = item2;
    tmp.setItems(tmpList,2);
    return tmp;
}

SECS2Item SECS2Item::mergeSECS2Item(SECS2Item *itemList1, int len1, SECS2Item *itemList2, int len2)
{
    SECS2Item tmp1;
    tmp1.setItems(itemList1,len1);
    SECS2Item tmp2;
    tmp2.setItems(itemList2,len2);
    SECS2Item tmp3 = SECS2Item::mergeSECS2Item(tmp1,tmp2);
    return tmp3;
}

SECS2Item SECS2Item::merge(SECS2Item *SECS2Item, int length)
{
    class SECS2Item tmp,res;
    tmp.setItems(SECS2Item,length);

    class SECS2Item tmpList[2];
    tmpList[0] = *this;
    tmpList[1] = tmp;
    res.setItems(tmpList,2);
    return res;
}

QString SECS2Item::int8String(QString leadingstr) const
{
    QString text;
    bool ok;
    QVector<int8_t> int8 = toInt8(&ok);
    if(ok)
    {
        for(int i =0; i < int8.size(); i++)
        {
            text += leadingstr;
            text += QString("<INT8, %1>\n").arg(int8.at(i));
        }
    }
    return text;
}
QString SECS2Item::int16String(QString leadingstr) const
{
    QString text;
    bool ok;
    QVector<int16_t> x = toInt16(&ok);
    if(ok)
    {
        for(int i =0; i < x.size(); i++)
        {
            text += leadingstr;
            text += QString("<INT16, %1>\n").arg(x.at(i));
        }
    }
    return text;
}
QString SECS2Item::int32String(QString leadingstr) const
{
    QString text;
    bool ok;
    QVector<int32_t> x = toInt32(&ok);
    if(ok)
    {
        for(int i =0; i < x.size(); i++)
        {
            text += leadingstr;
            text += QString("<INT32, %1>\n").arg(x.at(i));
        }
    }
    return text;
}
QString SECS2Item::int64String(QString leadingstr) const
{
    QString text;
    bool ok;
    QVector<int64_t> x = toInt64(&ok);
    if(ok)
    {
        for(int i =0; i < x.size(); i++)
        {
            text += leadingstr;
            text += QString("<INT64, %1>\n").arg(x.at(i));
        }
    }
    return text;
}
QString SECS2Item::uint8String(QString leadingstr) const
{
    QString text;
    bool ok;
    QVector<uint8_t> x = toUInt8(&ok);
    if(ok)
    {
        for(int i =0; i < x.size(); i++)
        {
            text += leadingstr;
            text += QString("<UINT8, %1>\n").arg(x.at(i));
        }
    }
    return text;
}
QString SECS2Item::uint16String(QString leadingstr) const
{
    QString text;
    bool ok;
    QVector<uint16_t> x = toUInt16(&ok);
    if(ok)
    {
        for(int i =0; i < x.size(); i++)
        {
            text += leadingstr;
            text += QString("<UINT16, %1>\n").arg(x.at(i));
        }
    }
    return text;
}
QString SECS2Item::uint32String(QString leadingstr) const
{
    QString text;
    bool ok;
    QVector<uint32_t> x = toUInt32(&ok);
    if(ok)
    {
        for(int i =0; i < x.size(); i++)
        {
            text += leadingstr;
            text += QString("<UINT32, %1>\n").arg(x.at(i));
        }
    }
    return text;
}
QString SECS2Item::uint64String(QString leadingstr) const
{
    QString text;
    bool ok;
    QVector<uint64_t> x = toUInt64(&ok);
    if(ok)
    {
        for(int i =0; i < x.size(); i++)
        {
            text += leadingstr;
            text += QString("<UINT64, %1>\n").arg(x.at(i));
        }
    }
    return text;
}
QString SECS2Item::floatString(QString leadingstr) const
{
    QString text;
    bool ok;
    QVector<float> x = toFloat(&ok);
    if(ok)
    {
        for(int i =0; i < x.size(); i++)
        {
            text += leadingstr;
            text += QString("<FLOAT, %1>\n").arg(x.at(i));
        }
    }
    return text;
}
QString SECS2Item::doubleString(QString leadingstr) const
{
    QString text;
    bool ok;
    QVector<double> x = toDouble(&ok);
    if(ok)
    {
        for(int i =0; i < x.size(); i++)
        {
            text += leadingstr;
            text += QString("<DOUBLE, %1>\n").arg(x.at(i));
        }
    }
    return text;
}
QString SECS2Item::boolString(QString leadingstr) const
{
    QString text;
    bool ok;
    QVector<bool> x = toBoolean(&ok);
    if(ok)
    {
        for(int i =0; i < x.size(); i++)
        {
            text += leadingstr;
            text += QString("<BOOL, %1>\n").arg(x.at(i));
        }
    }
    return text;
}
QString SECS2Item::binaryString(QString leadingstr) const
{
    QString text = leadingstr;
    bool ok;
    QVector<uint8_t> x = toUInt8(&ok);
    if(ok)
    {
        for(int i =0; i < x.size(); i++)
        {
            text += leadingstr;
            int xx = x.at(i);
            text += QString("<BINARY, 0x%1>\n").arg(xx, 2, 16);
        }
    }
    return text;
}
QString SECS2Item::ASCIIString(QString leadingstr) const
{
    QString text = leadingstr;
    bool ok;
    QString s = toASCII(&ok);
    text += QString("<ASCII, %1>\n").arg(s);
    return text;
}

QString SECS2Item::toXml(QString leadingStr) const
{
    QString text;
    QString ls = leadingStr + "    ";
    text += QString("%1<ITEM>\n").arg(leadingStr);
    text += QString("%1<BYTES>%2</BYTES>\n").arg(ls).arg(m_bytes);
    if( isList() )
    {
        text += QString("%1<TYPE>LIST</TYPE>\n").arg(ls);
        bool ok;
        QVector<SECS2Item> x = toItems(&ok);
        if(ok)
        {
            for(int i =0; i < x.size(); i++)
            {
                SECS2Item xx = x.at(i);
                text += xx.toXml(ls);
            }
        }
    }
    else
    {
        ls += "    ";

        switch (m_format)
        {
        case IFC_INT8:
            text += QString("%1<TYPE>INT8</TYPE>\n").arg(ls);
            text += int8String(ls);
            break;
        case IFC_ASCII :
            text += QString("%1<TYPE>ASCII</TYPE>\n").arg(ls);
            text += ASCIIString(ls);
            break;
        case IFC_JIS8:
            text += QString("%1<TYPE>JIS8</TYPE>\n").arg(ls);
            break;
        case IFC_LIST:
            break;
        case IFC_FLOAT:
            text += QString("%1<TYPE>FLOAT</TYPE>\n").arg(ls);
            text += floatString(ls);
            break;
        case IFC_INT16:
            text += QString("%1<TYPE>INT16</TYPE>\n").arg(ls);
            text += int16String(ls);
            break;
        case IFC_INT32:
            text += QString("%1<TYPE>INT32</TYPE>\n").arg(ls);
            text += int32String(ls);
            break;
        case IFC_INT64:
            text += QString("%1<TYPE>INT64</TYPE>\n").arg(ls);
            text += int64String(ls);
            break;
        case IFC_UINT8:
            text += QString("%1<TYPE>UINT8</TYPE>\n").arg(ls);
            text += uint8String(ls);
            break;
        case IFC_BINARY:
            text += QString("%1<TYPE>BINARY</TYPE>\n").arg(ls);
            text += binaryString(ls);
            break;
        case IFC_CHAR16:
            text += QString("%1<TYPE>CHAR16</TYPE>\n").arg(ls);
            break;
        case IFC_DOUBLE:
            text += QString("%1<TYPE>DOUBLE</TYPE>\n").arg(ls);
            text += doubleString(ls);
            break;
        case IFC_UINT16:
            text += QString("%1<TYPE>UINT16</TYPE>\n").arg(ls);
            text += uint16String(ls);
            break;
        case IFC_UINT32:
            text += QString("%1<TYPE>UINT32</TYPE>\n").arg(ls);
            text += uint32String(ls);
            break;
        case IFC_UINT64:
            text += QString("%1<TYPE>UINT64</TYPE>\n").arg(ls);
            text += uint64String(ls);
            break;
        case IFC_BOOLEAN:
            text += QString("%1<TYPE>BOOLEAN</TYPE>\n").arg(ls);
            text += boolString(ls);
            break;
        }
    }
    text += QString("%1</ITEM>\n").arg(leadingStr);
    return text;
}

QString SECS2Item::stringLog(QString leadingStr) const
{
    QString text;
    QString ls = leadingStr;
    if( isList() )
    {
        text += ls;
        text += QString("<ITEM, LIST, %1, [%2]>\n").arg(m_bytes).arg(m_name);
        ls += "    ";
        bool ok;
        QVector<SECS2Item> x = toItems(&ok);
        if(ok)
        {
            for(int i =0; i < x.size(); i++)
            {
                SECS2Item xx = x.at(i);
                text += xx.stringLog(ls);
            }
        }
    }
    else
    {
        text += ls;
        ls += "    ";
        switch (m_format)
        {
        case IFC_INT8:
            text += QString("<ITEM, INT8, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            text += int8String(ls);
            break;
        case IFC_ASCII :
            text += QString("<ITEM, ASCII, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            text += ASCIIString(ls);
            break;
        case IFC_JIS8:
            text += QString("<ITEM, JIS8, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            break;
        case IFC_LIST:
            break;
        case IFC_FLOAT:
            text += QString("<ITEM, FLOAT, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            text += floatString(ls);
            break;
        case IFC_INT16:
            text += QString("<ITEM, INT16, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            text += int16String(ls);
            break;
        case IFC_INT32:
            text += QString("<ITEM, INT32, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            text += int32String(ls);
            break;
        case IFC_INT64:
            text += QString("<ITEM, INT64, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            text += int64String(ls);
            break;
        case IFC_UINT8:
            text += QString("<ITEM, UINT8, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            text += uint8String(ls);
            break;
        case IFC_BINARY:
            text += QString("<ITEM, BINARY, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            text += binaryString(ls);
            break;
        case IFC_CHAR16:
            text += QString("<ITEM, CHAR16, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            break;
        case IFC_DOUBLE:
            text += QString("<ITEM, DOUBLE, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            text += doubleString(ls);
            break;
        case IFC_UINT16:
            text += QString("<ITEM, UINT16, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            text += uint16String(ls);
            break;
        case IFC_UINT32:
            text += QString("<ITEM, UINT32, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            text += uint32String(ls);
            break;
        case IFC_UINT64:
            text += QString("<ITEM, UINT64, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            text += uint64String(ls);
            break;
        case IFC_BOOLEAN:
            text += QString("<ITEM, BOOL, %1, [%2]>\n").arg(m_bytes).arg(m_name);
            text += boolString(ls);
            break;
        }
    }
    return text;
}
bool SECS2Item::isList() const
{
    ItemFormatCode code = static_cast<ItemFormatCode>(m_itemHeader[0] & 0b11111100);
    if(m_format == code)
    {
        return m_format == IFC_LIST;
    }
    else
    {
        return false;
    }
}

QVector<SECS2Item> SECS2Item::toItems(bool *ok) const
{
    if( !isList() )
    {
        if(ok) *ok = false;
        return QVector<SECS2Item> ();
    }
    return m_itemVector;
//    int lengthBytes = m_itemHeader[0] & 0x03;
//    int bytes = m_bytes;
//    int x1, x2, x3;
//    switch (lengthBytes)
//    {
//    case 0:
//        if(ok) *ok = false;
//        return QVector<SECS2Item> ();
//    case 1:
//        bytes = m_itemHeader[1];
//        break;
//    case 2:
//        x1 = m_itemHeader[2];
//        x2 = m_itemHeader[1];
//        bytes = (x2 << 8) + x1;
//        break;
//    case 3:
//        x1 = m_itemHeader[3];
//        x2 = m_itemHeader[2];
//        x3 = m_itemHeader[1];
//        bytes = (x3 << 16) + (x2 << 8) + x1;
//    }
//    if(bytes != m_bytes)
//    {
//        qDebug() << "Warning :bytes != m_bytes";
//    }

//    QVector<SECS2Item> ret;
//    QByteArray buffer = m_itemBody;
//    for(int i = 0; i < bytes; i++)
//    {
//        SECS2Item item;
//        int pos = item.loadFromByteArray(buffer);
//        if(pos > 0)
//        {
//            ret.append(item);
//        }
//        buffer = buffer.mid(pos, -1);
//    }
//    if(ok) *ok = true;
//    return ret;
}

bool isValidFormat(SECS2Item::ItemFormatCode format)
{
    switch (format & 0b11111100)
    {
    case SECS2Item::IFC_LIST :
    case SECS2Item::IFC_INT8 :
    case SECS2Item::IFC_INT16 :
    case SECS2Item::IFC_INT32 :
    case SECS2Item::IFC_INT64 :

    case SECS2Item::IFC_JIS8 :
    case SECS2Item::IFC_ASCII :

    case SECS2Item::IFC_FLOAT :
    case SECS2Item::IFC_DOUBLE :

    case SECS2Item::IFC_UINT32 :
    case SECS2Item::IFC_UINT16 :
    case SECS2Item::IFC_UINT8 :
    case SECS2Item::IFC_UINT64 :

    case SECS2Item::IFC_BINARY :
    case SECS2Item::IFC_CHAR16 :
    case SECS2Item::IFC_BOOLEAN :
        return true;
    }
    return false;
}

bool isListFormat(SECS2Item::ItemFormatCode format)
{
    switch (format & 0b11111100)
    {
    case SECS2Item::IFC_LIST:
        return true;
    default:
        break;
    }
    return false;
}

int itemHeaderSize(const QByteArray &array)
{
    SECS2Item::ItemFormatCode format = static_cast<SECS2Item::ItemFormatCode>(array.at(0) & 0b11111100);
    int size = array.at(0) & 0b11;
    size ++;
    if(!isValidFormat(format) || size == 1)
    {
        return -2;
    }
    if( size > array.size() )
    {
        return -3;
    }
    return size;
}

SECS2Item::ItemFormatCode itemFormat(const QByteArray &array)
{
    return static_cast<SECS2Item::ItemFormatCode>(array.at(0) & 0b11111100);
}

int itemByte(const QByteArray &array)
{
    int headerSize = itemHeaderSize(array);
    int bytes = 0;
    switch (headerSize)
    {
    case 2:
        bytes = static_cast<uint8_t>(array.at(1));
        break;
    case 3:
        bytes = static_cast<uint8_t>(array.at(1));
        bytes = (bytes << 8) + static_cast<uint8_t>(array.at(2));
        break;
    case 4:
        bytes = static_cast<uint8_t>(array.at(1));
        bytes = (bytes << 8) + static_cast<uint8_t>(array.at(2));
        bytes = (bytes << 8) + static_cast<uint8_t>(array.at(3));
        break;
    default:
        bytes = 0;
    }
    return bytes;
}



int SECS2Item::loadFromByteArray(const QByteArray &array)
{
    if(array.size() < 2) return -1;
    int shift = itemHeaderSize(array);
    m_format = static_cast<SECS2Item::ItemFormatCode>(array.at(0) & 0b11111100);
    m_bytes = itemByte(array);
    m_itemHeader = array.left(shift);
    m_itemVector.clear();
    if(m_format == SECS2Item::IFC_LIST)
    {
        SECS2Item it;
        QByteArray subArray = array.mid(shift);
        for(int i = 0; i < m_bytes; i ++)
        {
            int size = it.loadFromByteArray(subArray);
            if(size < 2) return size;
            m_itemBody.append(it.itemData());
            m_itemVector.append(it);
            shift += size;
            subArray = array.mid(shift);
        }
    }
    else
    {
        if(shift + m_bytes > array.size()) return -1;
        m_itemBody = array.mid(shift, shift + m_bytes);
        shift += m_bytes;
    }
    m_itemDataAll = m_itemHeader;
    m_itemDataAll.append(m_itemBody);

    return shift;
}

// 内部函数, 用于构造 Item Header （IH）
int SECS2Item::buildItemHeader()
{
    int lengthBytes = 1;
    if(m_bytes > 65535)
    {
        lengthBytes = 3;
        m_itemHeader.resize(1 + lengthBytes);
        m_itemHeader[1] = static_cast<char>(m_bytes >> 16);
        m_itemHeader[2] = static_cast<char>(m_bytes >> 8);
        m_itemHeader[3] = static_cast<char>(m_bytes >> 0);
    }
    else if(m_bytes > 255)
    {
        lengthBytes = 2;
        m_itemHeader.resize(1 + lengthBytes);
        m_itemHeader[1] = static_cast<char>(m_bytes >> 8);
        m_itemHeader[2] = static_cast<char>(m_bytes >> 0);
    }
    else
    {
        lengthBytes = 1;
        m_itemHeader.resize(1 + lengthBytes);
        m_itemHeader[1] = static_cast<char>(m_bytes >> 0);
    }
    m_itemHeader[0] = static_cast<char>(m_format) | static_cast<char>(lengthBytes);
    m_itemDataAll = m_itemHeader;

    return 1 + lengthBytes;
}

SECS2Item::SECS2Item(const SECS2Item &x)
{
    m_format = x.m_format;
    m_bytes = x.m_bytes;
    m_itemHeader = x.m_itemHeader;
    m_itemBody = x.m_itemBody;
    m_itemDataAll = x.m_itemDataAll;
    m_itemVector = x.m_itemVector;
    m_name = x.m_name;
}

void SECS2Item::setASCII(QString str)
{
    setASCII(str.toLatin1().constData());
}

void SECS2Item::setASCII(const char *str)
{
    m_format = SECS2Item::IFC_ASCII;
    m_bytes = static_cast<int>(strlen(str));
    buildItemHeader();
    m_itemBody.clear();
    m_itemBody.append(str);
    m_itemDataAll.append(str);
}

void SECS2Item::setBoolean(const bool x[], int N)
{
    m_format = SECS2Item::IFC_BOOLEAN;
    m_bytes = N;
    buildItemHeader();
    m_itemBody.resize(N);
    for(int i = 0; i < N; i++)
    {
        m_itemBody[i] = (x[i] != false);
    }
    m_itemDataAll.append(m_itemBody);
}

void SECS2Item::setBinary(const QByteArray &x)
{
   m_format = SECS2Item::IFC_BINARY;
   m_bytes = x.size();
   buildItemHeader();
   m_itemBody = x;
   m_itemDataAll.append(m_itemBody);
}

void SECS2Item::setJIS8(const char *str)
{
    m_format = SECS2Item::IFC_JIS8;
    m_bytes = static_cast<int>(strlen(str));
    buildItemHeader();
    m_itemBody.clear();
    m_itemBody.append(str);
    m_itemDataAll.append(m_itemBody);
}

void SECS2Item::setInt8(const QVector<int8_t> &x)
{
    int N = x.size();
    setInt8(x.constData(), N);
}

void SECS2Item::setInt8(const int8_t x[], int N)
{
    m_format = SECS2Item::IFC_INT8;
    m_bytes = N;
    buildItemHeader();
    m_itemBody.clear();
    m_itemBody.append(reinterpret_cast<const char *>(x), N);
    m_itemDataAll.append(m_itemBody);
}

void SECS2Item::setInt16(const int16_t x[], int N)
{
    m_format = SECS2Item::IFC_INT16;
    m_bytes = N * 2;
    buildItemHeader();
    m_itemBody.resize(m_bytes);
    const char * p = reinterpret_cast<const char *>(x);
    for(int i = 0; i < N; i++)
    {
        m_itemBody[2 * i + 0] = p[2 * i + 1];
        m_itemBody[2 * i + 1] = p[2 * i + 0];
    }
    m_itemDataAll.append(m_itemBody);
}

void SECS2Item::setInt32(const int32_t x[], int N)
{
    m_format = SECS2Item::IFC_INT32;
    m_bytes = N * 4;
    buildItemHeader();
    m_itemBody.resize(m_bytes);
    const char * p = reinterpret_cast<const char *>(x);
    for(int i = 0; i < N; i++)
    {
        m_itemBody[4 * i + 0] = p[4 * i + 3];
        m_itemBody[4 * i + 1] = p[4 * i + 2];
        m_itemBody[4 * i + 2] = p[4 * i + 1];
        m_itemBody[4 * i + 3] = p[4 * i + 0];
    }
    m_itemDataAll.append(m_itemBody);
}

void SECS2Item::setInt64(const int64_t x[], int N)
{
    m_format = SECS2Item::IFC_INT64;
    m_bytes = N * 8;
    buildItemHeader();
    m_itemBody.resize(m_bytes);
    const char * p = reinterpret_cast<const char *>(x);
    for(int i = 0; i < N; i++)
    {
        m_itemBody[8 * i + 0] = p[8 * i + 7];
        m_itemBody[8 * i + 1] = p[8 * i + 6];
        m_itemBody[8 * i + 2] = p[8 * i + 5];
        m_itemBody[8 * i + 3] = p[8 * i + 4];
        m_itemBody[8 * i + 4] = p[8 * i + 3];
        m_itemBody[8 * i + 5] = p[8 * i + 2];
        m_itemBody[8 * i + 6] = p[8 * i + 1];
        m_itemBody[8 * i + 7] = p[8 * i + 0];
    }
    m_itemDataAll.append(m_itemBody);
}

void SECS2Item::setUInt8(const uint8_t x[], int N)
{
    m_format = SECS2Item::IFC_UINT8;
    m_bytes = N;
    buildItemHeader();
    m_itemBody.clear();
    m_itemBody.append(reinterpret_cast<const char *>(x), N);
    m_itemDataAll.append(m_itemBody);
}

void SECS2Item::setUInt8(const uint8_t x)
{
    uint8_t y[] = {x};
    SECS2Item::setUInt8(y,1);
}

void SECS2Item::setUInt16(const uint16_t x[], int N)
{
    m_format = SECS2Item::IFC_UINT16;
    m_bytes = N * 2;
    buildItemHeader();
    m_itemBody.resize(m_bytes);
    const char * p = reinterpret_cast<const char *>(x);
    for(int i = 0; i < N; i++)
    {
        m_itemBody[2 * i + 0] = p[2 * i + 1];
        m_itemBody[2 * i + 1] = p[2 * i + 0];
    }
    m_itemDataAll.append(m_itemBody);
}

void SECS2Item::setUInt32(const uint32_t x[], int N)
{
    m_format = SECS2Item::IFC_UINT32;
    m_bytes = N * 4;
    buildItemHeader();
    m_itemBody.resize(m_bytes);
    const char * p = reinterpret_cast<const char *>(x);
    for(int i = 0; i < N; i++)
    {
        m_itemBody[4 * i + 0] = p[4 * i + 3];
        m_itemBody[4 * i + 1] = p[4 * i + 2];
        m_itemBody[4 * i + 2] = p[4 * i + 1];
        m_itemBody[4 * i + 3] = p[4 * i + 0];
    }
    m_itemDataAll.append(m_itemBody);
}

void SECS2Item::setUInt32(const uint32_t x)
{
    uint32_t y[]= {x};
    SECS2Item::setUInt32(y,1);
}

void SECS2Item::setItems(const QVector<SECS2Item> &x)
{
    int N = x.size();
    setItems(x.constData(), N);
}

void SECS2Item::setItems(const SECS2Item x[], int N)
{
    m_format = SECS2Item::IFC_LIST;
    m_bytes = N;

    buildItemHeader();
    m_itemBody.clear();
    m_itemVector.clear();
    for(int i = 0; i < N; i++)
    {
        m_itemVector.append(x[i]);
        m_itemBody.append(x[i].itemData());
    }   
    m_itemDataAll.append(m_itemBody);
}

void SECS2Item::setUInt64(const uint64_t x[], int N)
{
    m_format = SECS2Item::IFC_UINT64;
    m_bytes = N * 8;
    buildItemHeader();
    m_itemBody.resize(m_bytes);
    const char * p = reinterpret_cast<const char *>(x);
    for(int i = 0; i < N; i++)
    {
        m_itemBody[8 * i + 0] = p[8 * i + 7];
        m_itemBody[8 * i + 1] = p[8 * i + 6];
        m_itemBody[8 * i + 2] = p[8 * i + 5];
        m_itemBody[8 * i + 3] = p[8 * i + 4];
        m_itemBody[8 * i + 4] = p[8 * i + 3];
        m_itemBody[8 * i + 5] = p[8 * i + 2];
        m_itemBody[8 * i + 6] = p[8 * i + 1];
        m_itemBody[8 * i + 7] = p[8 * i + 0];
    }
    m_itemDataAll.append(m_itemBody);
}

QVector<bool> SECS2Item::toBoolean(bool *ok) const
{
    if(m_format != SECS2Item::IFC_BOOLEAN || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QVector<bool> ();
    }

    QVector<bool> ret(m_bytes);
    for(int i = 0; i < m_bytes; i++)
    {
        ret[i] = m_itemBody[i];
    }
    if(ok) *ok = true;
    return ret;
}

QByteArray SECS2Item::toBinary(bool *ok) const
{
    if(m_format != SECS2Item::IFC_BINARY || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QByteArray();
    }
    if(ok) *ok = true;
    return m_itemBody;
}

QByteArray SECS2Item::toJIS8(bool *ok) const
{
    if(m_format != SECS2Item::IFC_JIS8 || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QByteArray();
    }
    if(ok) *ok = true;
    return m_itemBody;
}

QString SECS2Item::toASCII(bool *ok) const
{
    if(m_format != SECS2Item::IFC_ASCII || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QString();
    }
    if(ok) *ok = true;
    return QString(m_itemBody);
}

QVector<int8_t> SECS2Item::toInt8(bool *ok) const
{
    if(m_format != SECS2Item::IFC_INT8 || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QVector<int8_t> ();
    }

    QVector<int8_t> ret(m_bytes);
    for(int i = 0; i < m_bytes; i++)
    {
        ret[i] = m_itemBody[i];
    }
    if(ok) *ok = true;
    return ret;
}

QVector<int16_t> SECS2Item::toInt16(bool *ok) const
{
    if(m_format != SECS2Item::IFC_INT16 || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QVector<int16_t> ();
    }

    int N = m_bytes / 2;
    QVector<int16_t> ret(N);
    char * p = reinterpret_cast<char *>(ret.data());
    for(int i = 0; i < N; i++)
    {
        p[2 * i + 0] = m_itemBody[2 * i + 1];
        p[2 * i + 1] = m_itemBody[2 * i + 0];
    }
    if(ok) *ok = true;
    return ret;
}

QVector<int32_t> SECS2Item::toInt32(bool *ok) const
{
    if(m_format != SECS2Item::IFC_INT32 || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QVector<int32_t> ();
    }

    int N = m_bytes / 4;
    QVector<int32_t> ret(N);
    char * p = reinterpret_cast<char *>(ret.data());
    for(int i = 0; i < N; i++)
    {
        p[4 * i + 0] = m_itemBody[4 * i + 3];
        p[4 * i + 1] = m_itemBody[4 * i + 2];
        p[4 * i + 2] = m_itemBody[4 * i + 1];
        p[4 * i + 3] = m_itemBody[4 * i + 0];
    }
    if(ok) *ok = true;
    return ret;
}

QVector<int64_t> SECS2Item::toInt64(bool *ok) const
{
    if(m_format != SECS2Item::IFC_INT64 || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QVector<int64_t> ();
    }

    int N = m_bytes / 8;
    QVector<int64_t> ret(N);
    char * p = reinterpret_cast<char *>(ret.data());
    for(int i = 0; i < N; i++)
    {
        p[8 * i + 0] = m_itemBody[8 * i + 7];
        p[8 * i + 1] = m_itemBody[8 * i + 6];
        p[8 * i + 2] = m_itemBody[8 * i + 5];
        p[8 * i + 3] = m_itemBody[8 * i + 4];
        p[8 * i + 4] = m_itemBody[8 * i + 3];
        p[8 * i + 5] = m_itemBody[8 * i + 2];
        p[8 * i + 6] = m_itemBody[8 * i + 1];
        p[8 * i + 7] = m_itemBody[8 * i + 0];
    }
    if(ok) *ok = true;
    return ret;
}

QVector<uint8_t> SECS2Item::toUInt8(bool *ok) const
{
    if(m_format != SECS2Item::IFC_UINT8 || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QVector<uint8_t> ();
    }

    QVector<uint8_t> ret(m_bytes);
    for(int i = 0; i < m_bytes; i++)
    {
        ret[i] = static_cast<uint8_t>(m_itemBody[i]);
    }
    if(ok) *ok = true;
    return ret;
}

QVector<float> SECS2Item::toFloat(bool *ok) const
{
    if(m_format != SECS2Item::IFC_FLOAT || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QVector<float> ();
    }

    int N = m_bytes / 4;
    QVector<float> ret(N);
    char * p = reinterpret_cast<char *>(ret.data());
    for(int i = 0; i < N; i++)
    {
        p[2 * i + 0] = m_itemBody[2 * i + 3];
        p[2 * i + 1] = m_itemBody[2 * i + 2];
        p[2 * i + 2] = m_itemBody[2 * i + 1];
        p[2 * i + 3] = m_itemBody[2 * i + 0];
    }
    if(ok) *ok = true;
    return ret;
}

QVector<double> SECS2Item::toDouble(bool *ok) const
{
    if(m_format != SECS2Item::IFC_DOUBLE || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QVector<double> ();
    }

    int N = m_bytes / 8;
    QVector<double> ret(N);
    char * p = reinterpret_cast<char *>(ret.data());
    for(int i = 0; i < N; i++)
    {
        p[2 * i + 0] = m_itemBody[2 * i + 7];
        p[2 * i + 1] = m_itemBody[2 * i + 6];
        p[2 * i + 2] = m_itemBody[2 * i + 5];
        p[2 * i + 3] = m_itemBody[2 * i + 4];
        p[2 * i + 4] = m_itemBody[2 * i + 3];
        p[2 * i + 5] = m_itemBody[2 * i + 2];
        p[2 * i + 6] = m_itemBody[2 * i + 1];
        p[2 * i + 7] = m_itemBody[2 * i + 0];
    }
    if(ok) *ok = true;
    return ret;
}

QVector<uint16_t> SECS2Item::toUInt16(bool *ok) const
{
    if(m_format != SECS2Item::IFC_UINT16 || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QVector<uint16_t> ();
    }

    int N = m_bytes / 2;
    QVector<uint16_t> ret(N);
    char * p = reinterpret_cast<char *>(ret.data());
    for(int i = 0; i < N; i++)
    {
        p[2 * i + 0] = m_itemBody[2 * i + 1];
        p[2 * i + 1] = m_itemBody[2 * i + 0];
    }
    if(ok) *ok = true;
    return ret;
}

QVector<uint32_t> SECS2Item::toUInt32(bool *ok) const
{
    if(m_format != SECS2Item::IFC_UINT32 || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QVector<uint32_t> ();
    }

    int N = m_bytes / 4;
    QVector<uint32_t> ret(N);
    char * p = reinterpret_cast<char *>(ret.data());
    for(int i = 0; i < N; i++)
    {
        p[4 * i + 0] = m_itemBody[4 * i + 3];
        p[4 * i + 1] = m_itemBody[4 * i + 2];
        p[4 * i + 2] = m_itemBody[4 * i + 1];
        p[4 * i + 3] = m_itemBody[4 * i + 0];
    }
    if(ok) *ok = true;
    return ret;
}

QVector<uint64_t> SECS2Item::toUInt64(bool *ok) const
{
    if(m_format != SECS2Item::IFC_UINT64 || m_bytes != m_itemBody.size())
    {
        if(ok) *ok = false;
        return QVector<uint64_t> ();
    }

    int N = m_bytes / 8;
    QVector<uint64_t> ret(N);
    char * p = reinterpret_cast<char *>(ret.data());
    for(int i = 0; i < N; i++)
    {
        p[8 * i + 0] = m_itemBody[8 * i + 7];
        p[8 * i + 1] = m_itemBody[8 * i + 6];
        p[8 * i + 2] = m_itemBody[8 * i + 5];
        p[8 * i + 3] = m_itemBody[8 * i + 4];
        p[8 * i + 4] = m_itemBody[8 * i + 3];
        p[8 * i + 5] = m_itemBody[8 * i + 2];
        p[8 * i + 6] = m_itemBody[8 * i + 1];
        p[8 * i + 7] = m_itemBody[8 * i + 0];
    }
    if(ok) *ok = true;
    return ret;
}

void SECS2Item::setFloat(const float x[], int N)
{
    m_format = SECS2Item::IFC_FLOAT;
    m_bytes = N * 4;
    buildItemHeader();
    m_itemBody.resize(m_bytes);
    const char * p = reinterpret_cast<const char *>(x);
    for(int i = 0; i < N; i++)
    {
        m_itemBody[4 * i + 0] = p[4 * i + 3];
        m_itemBody[4 * i + 1] = p[4 * i + 2];
        m_itemBody[4 * i + 2] = p[4 * i + 1];
        m_itemBody[4 * i + 3] = p[4 * i + 0];
    }
    m_itemDataAll.append(m_itemBody);
}

void SECS2Item::setDouble(const double x[], int N)
{
    m_format = SECS2Item::IFC_DOUBLE;
    m_bytes = N * 8;
    buildItemHeader();
    m_itemBody.resize(m_bytes);
    const char * p = reinterpret_cast<const char *>(x);
    for(int i = 0; i < N; i++)
    {
        m_itemBody[8 * i + 0] = p[8 * i + 7];
        m_itemBody[8 * i + 1] = p[8 * i + 6];
        m_itemBody[8 * i + 2] = p[8 * i + 5];
        m_itemBody[8 * i + 3] = p[8 * i + 4];
        m_itemBody[8 * i + 4] = p[8 * i + 3];
        m_itemBody[8 * i + 5] = p[8 * i + 2];
        m_itemBody[8 * i + 6] = p[8 * i + 1];
        m_itemBody[8 * i + 7] = p[8 * i + 0];
    }
    m_itemDataAll.append(m_itemBody);
}
