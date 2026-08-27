# Exercise 02: The Job Of Your Dreams

このREADMEは、CPP Module 00課題文のChapter II（General rules）とChapter VI（Exercise 02）に沿ったレビュー用メモです。

## 提出条件

| 項目 | 課題文の指定 |
|---|---|
| Directory | `ex02/` |
| Files to submit | `Makefile`, `Account.cpp`, `Account.hpp`, `tests.cpp` |
| Exercise固有の禁止事項 | None |

Exercise固有の禁止事項がなくても、CPP Module 00の共通規則は適用されます。課題文には、Exercise 02を完了しなくてもこのモジュールの合格は可能だと記載されています。

## 課題文の共通規則

- `c++ -Wall -Wextra -Werror` でコンパイルする
- `-std=c++98` を追加してもコンパイルできること
- 特に指定がなければ、出力は標準出力へ表示し、各メッセージを改行で終える
- 外部ライブラリ、C++11以降、Boostを使わない
- `*printf()`、`*alloc()`、`free()`を使わない
- `using namespace` と `friend` を使わない
- ヘッダ内に関数実装を書かず、必要な依存を含め、include guardを付ける
- C課題と同じMakefile規則に従う

一般規則ではModule 08より前のSTLコンテナ・アルゴリズムは禁止されています。一方、このExerciseで配布されるテストコード自体は `vector` と `algorithm` を使用しています。レビューでは、配布ファイルと受験者が再構築した `Account.cpp` を区別して確認します。

## 課題文が求めること

課題文では、次の3ファイルがモジュールのイントラページから提供されると説明されています。

- `Account.hpp`
- `tests.cpp`
- 見本のログファイル

受験者が行う中心作業は `Account.cpp` の再構築です。テストプログラムを実行した出力を、保存されたログの出力と一致させることが求められています。

## 課題文が認める出力差

### timestamp

課題文には、見本ログを作成したテストは過去に実行されたため、実行時のtimestampは当然異なると記載されています。

課題文には「生のUnix timestampを表示する」とは書かれていません。見本ログが示す形式は次のとおりです。

```text
[19920104_091532]
```

この例から確認できる表示形式は `[YYYYMMDD_HHMMSS]` です。レビューではtimestampの値そのものを見本ログと一致させず、同じ形式で実行時に生成されていることを確認します。

### デストラクタの順序

課題文は、デストラクタが呼ばれる順序はコンパイラやOSによって異なり、逆順になる場合があると明記しています。したがって、末尾の `closed` 行は順序だけを理由に不一致とはしません。

## レビュー手順

```sh
make fclean
make
./account >/tmp/cpp00-ex02-current.log
echo $?
```

終了ステータスが `0` であることを確認します。次に、比較対象からtimestampだけを取り除きます。

```sh
sed -E 's/^\[[0-9]{8}_[0-9]{6}\] //' 19920104_091532.log > /tmp/cpp00-ex02-reference.normalized.log
sed -E 's/^\[[0-9]{8}_[0-9]{6}\] //' /tmp/cpp00-ex02-current.log > /tmp/cpp00-ex02-current.normalized.log
```

この配布ログでは、最初の51行がデストラクタ出力より前です。その部分は順序を変えずに比較します。

```sh
diff -u \
  <(sed -n '1,51p' /tmp/cpp00-ex02-reference.normalized.log) \
  <(sed -n '1,51p' /tmp/cpp00-ex02-current.normalized.log)
```

最後の8行は、課題文が許容するデストラクタ順の違いだけを無視して比較します。

```sh
diff -u \
  <(tail -n 8 /tmp/cpp00-ex02-reference.normalized.log | sort) \
  <(tail -n 8 /tmp/cpp00-ex02-current.normalized.log | sort)
```

どちらも差分がなければ、課題文が認める差を除いて見本ログと一致しています。`<(...)` はbashまたはzshで実行してください。

## `Account.hpp` とログから確認する項目

- [ ] 口座作成時にindex、初期残高、口座数、全体残高を正しく設定する
- [ ] `displayAccountsInfos()` が口座数、合計残高、全体の入出金回数を表示する
- [ ] `displayStatus()` が口座ごとの残高と入出金回数を表示する
- [ ] `makeDeposit()` が口座と全体の残高・入金回数を更新する
- [ ] `makeWithdrawal()` が成功時だけ残高・出金回数を更新して `true` を返す
- [ ] 残高不足時は状態を変更せず `withdrawal:refused` を表示して `false` を返す
- [ ] 各ログ行がtimestampから始まる
- [ ] timestamp以外の句読点、項目名、項目順、値が見本ログと一致する
- [ ] `closed` 行の順序を除き、各口座の最終状態が見本ログと一致する
- [ ] 共通禁止事項に違反していない
- [ ] Makefileの `all`, `clean`, `fclean`, `re` が動作する

## 課題文が指定していないこと

- timestampをUnix epochからの秒数で表示すること
- timestamp取得・整形に使う具体的な関数
- デストラクタを見本ログと同じ順序で呼ぶこと

timestampについて課題文が直接指定しているのは「見本ログとは値が異なる」という点です。`[YYYYMMDD_HHMMSS]` は配布ログから読み取れる形式であり、生のUnix秒を要求する根拠は課題文にはありません。

## この提出の実装メモ

この実装は `std::time` で現在時刻を取得し、`std::strftime` で見本と同じ `[YYYYMMDD_HHMMSS]` 形式へ整形しています。口座数、合計残高、全体の入出金回数は、配布された `Account.hpp` の宣言どおりstaticメンバとして定義しています。