## CMakeList.txtのサンプル
### 概要
これはCMake及びCMakeList.txtのサンプルです。
各種コンパイラ、ライブラリなど自分の環境に合わせて書き換えて下さい。


### サンプルの必要環境
- CMake
- clang++
- boost.Test
- Google-perftools


### 使い方
#### ディレクトリ構造
- .
  - CMakeList.txt
  - unit_tests.cmake: ユニットテストの設定ファイル
  - bin: 実行可能ファイル出力先
  - include: ヘッダディレクトリ
    - my: サブディレクトリ
  - src: ソースディレクトリ
    - main.cc: main関数を含むソース
    - my: サブディレクトリ
  - tests: ユニットテストディレクトリ

#### 基本
デバッグビルドの場合は以下のコマンドを実行してください。
> cmake -DCMAKE_BUILD_TYPE=DEBUG .

プロファイリングビルドの場合は以下のコマンドを実行してください。
> cmake -DCMAKE_BUILD_TYPE=PROFILE .

リリースビルドの場合は以下のコマンドを実行してください。
> cmake -DCMAKE_BUILD_TYPE=RELEASE .

上記のコマンドを実行すると、Linuxの場合はMakefileを、Visual Studioがインストー
ルされたWindowsならばVisual Studioのプロジェクトを生成します。

Linuxの場合Makefileが生成された後、以下のコマンドを実行することで実行可能ファイ
ルを生成します。
> make

ビルドが成功すると、binディレクトリにバイナリmy_projectが生成されます。デバッグ
ビルドの場合はさらに二つのユニットテストmy_testとfailure_testが生成されます。

#### ユニットテスト
CMakeはユニットテストを自動実行するためのツールCTestが同梱されています。

このサンプルプロジェクトではmy_testとfailure_testの二つのユニットテストをコンパ
イルし、CTestを用いて実行するサンプルが含まれます。ユニットテストをコンパイルす
るためには、デバッグビルドでプロジェクトをビルドします。

ユニットテストを実行するには、ビルド後に以下のコマンドを実行します。
> ctest 

ユニットテストのログは、デフォルトではTesting/Temporary/LastTest.logに格納され
ます。

このサンプルではadd_unit_testマクロを用いてユニットテストを追加することができま
す。add_unit_testマクロの詳細は以下の通りです。
> add_unit_test(
>   ユニットテスト名
>   ソースパス...
> )


### ライセンス
LICENSEを参照
