#include <QByteArray>
#include <QDebug>

static constexpr char c_alac_header[] = { '\x0c', '\x00', '\x00', '\x00', 'f', 'r', 'm', 'a', 'a', 'l', 'a', 'c' };

int main()
{
  // Create byte array with same data as ALAC header.
  QByteArray header{};
  
  uint32_t atom_size = 12;
  header.append(reinterpret_cast<const char *>(&atom_size), sizeof(atom_size));
  header.append("frma", 4);
  header.append("alac", 4);

  qDebug() << "ALAC header content is:" << header.toHex();

  if (header.startsWith(QByteArray::fromRawData(c_alac_header, sizeof(c_alac_header))))
  {
    qDebug() << "ALAC header matches!";
  }

  QByteArray qba = QByteArray::fromRawData(c_alac_header, sizeof(c_alac_header)) + header;
  qDebug() << "It is simple to join 2 byte arrays with Qt: " << qba.toHex();
}
