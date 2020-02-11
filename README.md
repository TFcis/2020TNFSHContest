# 2020臺南一中校內賽（TOI校內初選）

## Quick Links

| ID | gen | solution | tests | statement | validator | config |
| --- | --- | --- | --- | --- | --- | --- |
| Card | [gen](Card/gen) | [solution](Card/solution) | [tests](Card/tests) | [statement](Matching/statement) [problem](Card/statement/problem.md) | [validator](Card/validator) | [problem](Route/problem.json) [solutions](Route/solutions.json) [subtasks](Route/subtasks.json) |
| Matching | [gen](Matching/gen) | [solution](Matching/solution) | [tests](Matching/tests) | [statement](Matching/statement) [problem](Matching/statement/problem.md) | [validator](Matching/validator) |[problem](Matching/problem.json) [solutions](Matching/solutions.json) [subtasks](Matching/subtasks.json) |
| Puyo | [gen](Puyo/gen) | [solution](Puyo/solution) | [tests](Puyo/tests) | [statement](Matching/statement) [problem](Puyo/statement/problem.md) | [validator](Puyo/validator) | [problem](Route/problem.json) [solutions](Route/solutions.json) [subtasks](Route/subtasks.json) |
| Route | [gen](Route/gen) | [solution](Route/solution) | [tests](Route/tests) | [statement](Route/statement) [problem](Route/statement/problem.md) | [validator](Route/validator) | [problem](Route/problem.json) [solutions](Route/solutions.json) [subtasks](Route/subtasks.json) |
| Swap | [gen](Swap/gen) | [solution](Swap/solution) | [tests](Swap/tests) | [statement](Matching/statement) [problem](Swap/statement/problem.md) | [validator](Swap/validator) | [problem](Route/problem.json) [solutions](Route/solutions.json) [subtasks](Route/subtasks.json) |
| Tree | [gen](Tree/gen) | [solution](Tree/solution) | [tests](Tree/tests) | [statement](Matching/statement) [problem](Tree/statement/problem.md) | [validator](Tree/validator) | [problem](Route/problem.json) [solutions](Route/solutions.json) [subtasks](Route/subtasks.json) |

## 資料夾結構
每題中包含以下目錄和檔案：
 - checker: 檢查輸出與標準答案是否相等的程式
 - gen: 所有產測資相關的程式碼，參見[TPS的說明](https://github.com/ioi-2017/tps/tree/master/docs#gen)
 - gen/data: 測資產生指令，參見[TPS的說明](https://github.com/ioi-2017/tps/tree/master/docs#gendata)
 - scripts: TPS所使用的腳本
 - solution: 標程及其他解法程式碼（包含所有拿部分分的程式碼），不要跟 validator 搞混
 - statement: 題本
 - statement/problem.md: （TPS格式）markdown 格式的題目敘述，之後會以 pandoc 輸出成 PDF
 - statement/problem.pdf: （TPS格式）用 `tps statement` 輸出的 PDF 題目敘述
 - tests: 測試資料
 - tests/mapping: 各子任務所屬測資檔案對應表（`tps gen` 自動產生），使用於自動匯入CMS時
 - validator: 驗證測資格式是否正確，是否符合範圍限制，各子任務是否符合各自限制，不要跟 solution 搞混
 - problem.json: 題目設定，包含時限及CMS設定
 - solutions.json: 標程設定，用以產生輸出檔的標程參數為 `"verdict": "model_solution"`
 - subtasks.json: 子任務分數設定
 
