# Derleyici-Compiler
Programlama dillerinde derleyici verilen kaynak kodu bir metin dosyası olarak okur ve dosyanın 
içeriğini bir diziye attıktan sonra dilin gramer kurallarına göre kelimeleştirme işlemini 
gerçekleştirirler. Kelimeleştirme işlemi bittikten sonra gramer kural testi yapılır. Bu çalışmada 
aşağıda verilen kodlar ve gramer kuralları kullanılacaktır.

TOP OP1,OP2
CRP OP1,OP2
BOL OP1,OP2
CIK OP1,OP2
DS ETIKET
DSD ETIKET
DAL ETIKET
DK ETIKET
DB ETIKET
ATM OP1,OP2
VE OP1,OP2
VEY OP1,OP2

Gramer kuralları
<program> -> <aritmetik> | <mantıksal> | <dallanma>
<aritmetik> -> TOP <op>,<op> | CRP <op>,<op> | BOL <op>,<op> | CIK <op>,<op> | ATM <op>,<op>
<mantıksal> -> VE <op>,<op> | VEY <op>,<op>
<dallanma> -> DS <etiket> | DSD <etiket> | DAL <etiket> | DK <etiket> | DB <etiket>
<op> -> AX | BX | CX | DX | [<sabit>] | <sabit>
<sabit> -> 0 | 1 | 2 | …. | 255
<etiket> -> ETIKET1 | ETIKET2 | … | ETIKET9

şeklinde verilen El-Ceziri işlemcinin Assembler dilinin komutları ve grameridir.

Bu düşünce ile 8-bitlik bir El-Ceziri işlemcisinin olduğu varsayılsın. Bu işlemcinin RAM 8-bitlik 256 byte (hafıza) bulunmaktadır. 
Aynı zamanda üzerinde AX, BX, CX, DX şeklinde dört tane 8-bitlik kayıtçı (register) bulunmaktadır.

Bu çalışmada kaynak kodun dosyasının ismi klavyeden okunacaktır ve bu dosyadan okuma 
yapılacaktır. Okuma tamamlandıktan sonra kelimeleştirme işlemi yapılacaktır. Daha sonra grammer hatası varsa kullanıcıya bildirilecektir.
Eğer grammer hatası yoksa kaynak kod ne iş yapıyorsa, hazırlanan program da aynı işi yapacaktır. Program bitiminde bütün 
registerların içeriği ekrana yazılacaktır ve eğer bellek kullanıldıysa, sadece belleğin o elemanı veya
elemanları ekrana yazılacaktır.
