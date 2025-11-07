# standard_assignment
標準課題 ロボット側プログラム

##回路について
<img src="./schdoc/raspberry_pi_sch1.pdf"/>

ハードウェアの機能を使って生成したPWM波形を74HC00(NAND)ゲートを用いて、モータドライバのIN1，IN2に直接入力
Vrefピンにつながる可変抵抗で2.5[V] - 5[V]の範囲で調整可能(MAX 4[V]までで調整)
モータドライバ データシート https://toshiba.semicon-storage.com/info/TB67H450FNG_datasheet_ja_20201126.pdf?did=65345&prodName=TB67H450FNG
