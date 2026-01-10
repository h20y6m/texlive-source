# Windows MSVC 用 TeX Live ビルドスクリプト


## 要件

  * Python 3.11 以上
  * [Meson](https://mesonbuild.com/) 1.1.0 以上
    - （オプション） Ninja
  * Visual Studio 2017 以上
    - （必須）C++ によるデスクトップ開発


## ビルド手順

スタートメニューから「x64 Native Tools Command Prompt for VS 2022」等を起動する。
またはコマンドプロンプトから以下を実行する。

```cmd
rem 例：Visual Studio Community 2022 で x64 をビルドする場合
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
```

ソースディレクトリに移動し以下のコマンドを実行する。

```cmd
cd build-windows
meson setup ..\Work
cd  ..\Work
meson compile
meson install --destdir=..\inst
```


## Visual Studio 上でのデバッグ

上記のビルド手順の `meson setup` のときに `--backend vs` オプションを指定すると `Work` ディレクトリに `texlive.sln` が生成されるので、それを Visual Studio で開く。

デバッグ対象を「スタートアッププロジェクト」に設定し、
「プロパティ」→「デバッグ」の「環境」に以下のように設定する（一例）。

```
TEXMFCNF=C:\texlive\2025;C:\texlive\2025\texmf-dist\web2c
TEXMFROOT=C:\texlive\2025
PATH=$(SolutionDir)libs\icu;$(SolutionDir)texk\kpathsea;$(Path)
```

### TeX エンジンのデバッグ

`platex.exe` 等の場合はフォーマットを作成する必要がある。

「コマンド引数」に以下のように指定し一度実行する。

```
-ini -etex platex.ini
```

文字列やメモリレイアウトが変わるたびにフォーマットを再度作成する。

### XeTeX 系エンジンのデバッグ

「コマンド引数」に `-no-pdf` オプションを入れてバックグラウンドで `xdvipdfmx.exe` を起動しないようにするとよい。


## ソースコードについて

以下のディレクトリのファイルは角藤氏の `windows-src2025.tar.xz` に含まれているものである。

  * `libs/expat/expat-src`
  * `libs/fontconfig/fontconfig-src`

また `config.h.in`/`c-auto.h.in` についても同様に `windows-src2025.tar.xz` に含まれる `config.h`/`c-auto.h` をもとに作成している。

