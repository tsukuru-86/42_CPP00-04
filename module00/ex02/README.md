# 銀行口座管理システム解説書

## 1. プログラム概要
このプログラムは銀行口座の基本的な操作（作成、入金、引き出し、残高照会）をシミュレートするシステムです。

## 2. ファイル構成
- `Account.hpp`: アカウントクラスの定義
- `Account.cpp`: アカウントクラスの実装
- `Tests.cpp`: テストケースの実装
- `19920104_091532.log`: 期待される出力のサンプル

## 3. クラス設計（Account.hpp）

### 3.1 静的メンバ変数
```cpp
static int _nbAccounts;      // アカウントの総数
static int _totalAmount;     // 全アカウントの総残高
static int _totalNbDeposits; // 全アカウントの総入金回数
static int _totalNbWithdrawals; // 全アカウントの総引き出し回数
```

### 3.2 インスタンスメンバ変数
```cpp
int _accountIndex;    // アカウント番号
int _amount;         // 残高
int _nbDeposits;    // このアカウントの入金回数
int _nbWithdrawals; // このアカウントの引き出し回数
```

### 3.3 主要メソッド
- コンストラクタ：初期預金額を受け取り口座を作成
- デストラクタ：口座の終了処理
- `makeDeposit`: 入金処理
- `makeWithdrawal`: 引き出し処理
- `displayStatus`: 口座状態の表示

## 4. 実装の詳細（Account.cpp）

### 4.1 タイムスタンプ処理
```cpp
void Account::_displayTimestamp(void) {
    std::cout << "[19920104_091532] ";
}
```
- すべての操作ログに付加される固定のタイムスタンプ
- 実際の時刻ではなく、テスト用の固定値を使用

### 4.2 アカウント作成処理
```cpp
Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts++;  // アカウント番号の割り当て
    _amount = initial_deposit;      // 初期残高の設定
    _totalAmount += initial_deposit; // 総残高の更新
    // ... 出力処理 ...
}
```

### 4.3 入金処理
```cpp
void Account::makeDeposit(int deposit) {
    _amount += deposit;         // 残高更新
    _totalAmount += deposit;    // 総残高更新
    _nbDeposits++;             // 入金回数更新
    _totalNbDeposits++;        // 総入金回数更新
    // ... 出力処理 ...
}
```

### 4.4 引き出し処理
```cpp
bool Account::makeWithdrawal(int withdrawal) {
    if (_amount < withdrawal) { // 残高チェック
        // ... 引き出し拒否の出力 ...
        return false;
    }
    _amount -= withdrawal;      // 残高更新
    _totalAmount -= withdrawal; // 総残高更新
    _nbWithdrawals++;          // 引き出し回数更新
    _totalNbWithdrawals++;     // 総引き出し回数更新
    // ... 出力処理 ...
    return true;
}
```

## 5. テストケース（Tests.cpp）

### 5.1 テストデータ
```cpp
int const amounts[] = { 42, 54, 957, 432, 1234, 0, 754, 16576 }; // 初期預金額
int const d[] = { 5, 765, 564, 2, 87, 23, 9, 20 };              // 入金テスト額
int const w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };        // 引き出しテスト額
```

### 5.2 テスト手順
1. 複数アカウントの作成
2. 各アカウントの状態表示
3. 一連の入金処理
4. 状態確認
5. 一連の引き出し処理
6. 最終状態確認

## 6. 出力フォーマット

### 6.1 アカウント作成時
```
[timestamp] index:N;amount:M;created
```

### 6.2 入金時
```
[timestamp] index:N;p_amount:M;deposit:D;amount:A;nb_deposits:X
```

### 6.3 引き出し時
```
[timestamp] index:N;p_amount:M;withdrawal:W;amount:A;nb_withdrawals:X
```
または
```
[timestamp] index:N;p_amount:M;withdrawal:refused
```

## 7. メモリ管理の特徴
- `std::vector`を使用したアカウント管理
- デストラクタの呼び出しは逆順（LIFO原則）
- メモリリークなし（自動メモリ管理）

## 8. エラー処理
- 引き出し時の残高チェック
- 不正な操作の防止（privateコンストラクタ）

## 9. コンパイルと実行

### 9.1 コンパイル方法
```bash
make        # プログラムをコンパイル
make clean  # オブジェクトファイルを削除
make fclean # オブジェクトファイルと実行ファイルを削除
make re     # 完全に再コンパイル
```

### 9.2 実行方法
```bash
./account
```
実行すると、テストケースが自動的に実行され、結果が標準出力に表示されます。