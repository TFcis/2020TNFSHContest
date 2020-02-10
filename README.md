# 2020臺南一中校內賽（TOI校內初選）

## Quick Links

| ID | gen | solution | tests | statement | validator | others |
| --- | --- | --- | --- | --- | --- | --- |
| Card | [gen](Card/gen) | [solution](Card/solution) | [tests](Card/tests) | [statement](Matching/statement) [problem.md](Card/statement/problem.md) | [validator](Card/validator) | |
| Matching | [gen](Matching/gen) | [solution](Matching/solution) | [tests](Matching/tests) | [statement](Matching/statement) [problem.md](Matching/statement/problem.md) | [validator](Matching/validator) | [problem.json](Matching/problem.json) |
| Puyo | [gen](Puyo/gen) | [solution](Puyo/solution) | [tests](Puyo/tests) | [statement](Matching/statement) [problem.md](Puyo/statement/problem.md) | [validator](Puyo/validator) | |
| Route | [gen](Route/gen) | [solution](Route/solution) | [tests](Route/tests) | [statement](Route/statement) [problem.md](Route/statement/problem.md) | [validator](Route/validator) | [problem.json](Route/problem.json) [solutions.json](Route/solutions.json) |
| Swap | [gen](Swap/gen) | [solution](Swap/solution) | [tests](Swap/tests) | [statement](Matching/statement) [problem.md](Swap/statement/problem.md) | [validator](Swap/validator) | |
| Tree | [gen](Tree/gen) | [solution](Tree/solution) | [tests](Tree/tests) | [statement](Matching/statement) [problem.md](Tree/statement/problem.md) | [validator](Tree/validator) | |

## 資料夾結構
每題中包含以下目錄和檔案：
 - gen: 所有產測資相關的程式碼
 - gen/data: 測資產生指令，參見[TPS的說明](https://github.com/ioi-2017/tps/tree/master/docs#gendata)
 - scripts: TPS所使用的腳本
 - solution: 所有標程
 - tests: 測試資料
 - tests/mapping: 各子任務所屬測資檔案對應表（`tps gen` 自動產生）
 - statement: 題本
 - statement/problem.md: （TPS格式）markdown 格式的題目敘述，之後會以 pandoc 輸出成 PDF
 - statement/problem.pdf: （TPS格式）用 `tps statement` 輸出的 PDF 題目敘述
 - validator: 驗題相關的所有程式
 - problem.json: 題目設定，包含時限及CMS設定
 - solutions.json: 標程設定，用以產生輸出檔的標程參數為 `"verdict": "model_solution"`
 - subtasks.json: 子任務分數設定
 