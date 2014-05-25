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

上記のコマンドを実行すると、Linuxの場合はMakefileを、Visual Studioがインスト
ールされたWindowsならばVisual Studioのプロジェクトを生成します。

Linuxの場合Makefileが生成された後、以下のコマンドを実行することで実行可能
ファイルを生成します。
> make

### ライセンス
LICENSEを参照
