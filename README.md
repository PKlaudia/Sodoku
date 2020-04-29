# Sodoku

A feladat a meglevő widgetkészletet felhasználva és azt kibővítve egy egyszerűbb játékprogram megírása. 

A közös követelmények:

a programnak le kell fordulnia, futnia kell, minden lehetséges felhasználói viselkedést programhiba nélkül kezelnie kell ("bolondbiztos")
a programnak tartalmaznia kell a már megkezdett widgetkészletet. Minden olyan programkomponensnek, ami a képernyőre rajzol, widget leszármazottnak kell lennie. Az eseménykezelő komponensnek (pl "JatekMester") külön osztályban kell lennie, a main() függvényben nem szerepelhet graphicslib hivatkozás
NEM kötelező a kétszemélyes játékokba gépi játékost írni, azonban extra pontot lehet érte kapni. Ilyen extra pontot csak az olyan játéknál lehet kapni, amelyikben van kihívás a gépi játékosban.
A grafikus felület és a játéklogika külön osztályba kell kerüljön. Legjobb megoldás, ha a játékszabályokat a JátékMester osztály érvényesíti, és a vonatkozó widgetek csak megjelenítenek, illetve lépési szándékokat továbbítanak a JátékMesternek.
A játékok implementálásakor érdemes maximalizálni a változtatás nélkül felhasznált widgetek körét, de ezen túl a játékra specializált widgetek létrehozása sokszor nem elkerülhető, sőt néha a legjobb megoldás. Mérlegelendő, hogy a játéktér felbontható-e widgetekre, vagy kényelmesebb-e egy nagy widgetként implementálni a játékteret. Mindkét irányzattal lehet maximumpontot kapni.
A maximum pontos beadandó githubra feltöltött, verziókövető rendszert érdemben használó formában van beadva. Elfogadható az, hogy egy működő working tree (.git alkönyvtárat tartalmazó könyvtár) van feltöltve, de az is, ha csak egy linket tartalmazó szövegfájl egy működő github repositoryra hivatkozva. A repositorynak publikusnak kell lennie. Ez a kódminőségre adható pontszámból 1-4 pontot tesz ki. 1 pont a kész program feltöltése, 4 pont az, ha a fejlesztés menete a githubos repositoryban jól követhető. Akik korábban töltik fel, például mert ezen feladatkiírás előtt elkezdtek dolgozni, akkor is megkaphatják a 4 pontot, ha csak az utolsó két heti munka látszik a repositoryban.

7. Sudoku
Számbeállító widgetekkel 9x9 sudoku Néhány pályát lehessen megoldani, amiket akár fájlból betölthet a program. A maximum pontos beadandó jelzi, ha a felhasználó által építgetett megfejtésben önellentmondás van (pl pirossá válik a kétszer felhasznált szám). Az nem jó, ha csak a végső megoldással veti össze a program az állapotot, mivel játékromboló hatása van.

Extra pont lehetőségek:
pályagenerátor, ami egyértelműen megoldható pályát tud generálni.
