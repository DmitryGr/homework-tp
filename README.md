# PatternsCollection
Кодовая база примеров паттернов проектирования по курсу "Технологии программирования, МФТИ"

## Содержание

* Порождающие паттерны:
  * [Factory Method](/FactoryMethod/python-source)
  * [Abstract Factory](/AbstractFactory)
    * [C++](/AbstractFactory/cpp-source)
    * [Python](/AbstractFactory/python-source)
  * [Builder](/Builder/python-source)
  * [Prototype](/Prototype/cpp-source)
  * [Adapter](/Adapter/cpp-source)
  * [Bridge](/Bridge/cpp-source)
  
 Для запуска проекта было сделано следующее:
 
 1) установлены недостающие библиотеки
 
 2) прописаны пути при запуске cmake
 
 3) при запуске cmake, make, make install с ON_PI = ON получен бинарник /usr/local/bin/Facade
 
 4) запущен бинарник с помощью установки линка на библиотеки в /usr/local/lib, заархивирована папка usr
 
 5) получена информация о классах проекта
