# Exercise 00: Megaphone

このREADMEは、CPP Module 00課題文のChapter II（General rules）とChapter IV（Exercise 00）に沿ったレビュー用メモです。

## 提出条件

| 項目 | 課題文の指定 |
|---|---|
| Directory | `ex00/` |
| Files to submit | `Makefile`, `megaphone.cpp` |
| Exercise固有の禁止事項 | None |

「Forbidden: None」はExercise固有の追加禁止事項がないという意味です。次の共通規則は適用されます。

## 課題文の共通規則

- `c++ -Wall -Wextra -Werror` でコンパイルする
- `-std=c++98` を追加してもコンパイルできること
- 特に指定がなければ、出力は標準出力へ表示し、各メッセージを改行で終える
- 外部ライブラリ、C++11以降、Boostを使わない
- `*printf()`、`*alloc()`、`free()`を使わない
- `using namespace` と `friend` を使わない
- Module 08より前ではSTLのコンテナとアルゴリズムを使わない
- ヘッダ内に関数実装を書かない（関数テンプレートを除く）
- C課題と同じMakefile規則に従う

## 課題文が求める動作

課題文は、実行例と同じ動作をするC++プログラムを求めています。

- コマンドライン引数の文字を大文字にする
- 複数の引数は、プログラム側で区切りを追加せず順番に出力する
- 引数がない場合は指定された固定メッセージを出力する
- 出力の最後を改行する

課題文には「C++らしい方法で解くこと」とも記載されています。

## 課題文の実行例

```console
$> ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$> ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$> ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

## レビュー手順

```sh
make fclean
make
./megaphone "shhhhh... I think the students are asleep..."
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
./megaphone
make re
make clean
make fclean
```

## チェックリスト

- [ ] 提出対象が `Makefile` と `megaphone.cpp` である
- [ ] 必須フラグで警告・エラーなくビルドできる
- [ ] 課題文の3つの実行例と出力が一致する
- [ ] 複数引数の順番を保ち、余計な区切りを追加しない
- [ ] 数字、記号、既に大文字の文字を壊さない
- [ ] 各出力が改行で終わる
- [ ] 共通禁止事項に違反していない
- [ ] Makefileの `all`, `clean`, `fclean`, `re` が動作する

## 課題文が指定していないこと

- 改行に `std::endl` と `\n` のどちらを使うか
- 大文字変換をどの関数で実装するか
- ループをどの形で書くか

したがって、これらは出力・コンパイル・共通規則を満たす限り、課題違反として扱う根拠にはなりません。

## この提出の実装メモ

この実装は `std::toupper` を使っています。引数を `unsigned char` へ変換してから渡しているのは、符号付き `char` の負値による未定義動作を避けるためです。これは課題文の追加要件ではなく、実装上の安全対策です。
