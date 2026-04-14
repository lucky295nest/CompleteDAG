# Návod na zprovoznění

## Klonování repozitáře

```shell
git clone --depth=1 https://github.com/lucky295nest/CompleteDAG.git
```

## Build

Vytvořit `build` složku a přesunout se do ní:

```shell
mkdir build
cd build
```

Použít CMake:

```shell
cmake ..
```

Zkompilovat:

```shell
make
```

Executable se vytvoří ve složce `build`.

Použití:

```shell
./CompleteDAG vstupni_soubor.txt vystupni_soubor.txt
```

---

## Příklad spuštění

> Příklad pro jeden z testů ve složce `tests-and-outputs`

Výstupní soubor se **nevytvoří automaticky**, musí existovat předem.

```shell
touch my-output.txt
./CompleteDAG ../tests-and-outputs/test-1.txt ./my-output.txt
```

---

## Generování dokumentace (Doxygen)

> Doxygen musí být nainstalovaný

```shell
cd ..
doxygen Doxyfile
```

HTML dokumentace se vytvoří ve složce `docs`.

Otevření:

```shell
cd docs/html/
firefox index.html
```

---

## Zdroje

* https://www.w3schools.com
* https://en.cppreference.com/
* https://en.wikipedia.org/wiki/Topological_sorting
