# 2020臺南一中校內賽（TOI校內初選）

每題中包含以下目錄和檔案：
 - gen: 所有產測資相關的程式碼
 - scripts: TPS所使用的腳本
 - solution: 所有標程
 - tests: 測試資料
 - statement: 題本
 - statement/problem.md: （TPS格式）markdown 格式的題目敘述，之後會以 pandoc 輸出成 PDF
 - statement/problem.pdf: （TPS格式）用 `tps statement` 輸出的 PDF 題目敘述
 - validator: 驗題相關的所有程式
 - problem.md: （舊格式）markdown 格式的題目敘述，之後會以 pandoc 輸出成 PDF
 - problem.pdf: （舊格式）用 `compile_pdf.sh` 輸出的 PDF 題目敘述
 - score.txt: CMS 上的 Score Type 和 Score Parameters
 
使用 `newtask.sh` 建立題目資料夾結構

## Quick Links

| ID | gen | solution | tests | statement | validator | others |
| --- | --- | --- | --- | --- | --- | --- |
| Card | [gen](Card/gen) | [solution](Card/solution) | [tests](Card/tests) | [problem.md](Card/problem.md) | [validator](Card/validator) | |
| Matching | [gen](Matching/gen) | [solution](Matching/solution) | [tests](Matching/tests) | [statement](Matching/statement) [problem.md](Matching/statement/problem.md) | [validator](Matching/validator) | [problem.json](Matching/problem.json) |
| Puyo | [gen](Puyo/gen) | [solution](Puyo/solution) | [tests](Puyo/tests) | [problem.md](Puyo/problem.md) | [validator](Puyo/validator) | |
| Route | [gen](Route/gen) | [solution](Route/solution) | [tests](Route/tests) | [statement](Route/statement) [problem.md](Route/statement/problem.md) | [validator](Route/validator) | [problem.json](Route/problem.json) [solutions.json](Route/solutions.json) |
| Swap | [gen](Swap/gen) | [solution](Swap/solution) | [tests](Swap/tests) | [problem.md](Swap/problem.md) | [validator](Swap/validator) | |
| Tree | [gen](Tree/gen) | [solution](Tree/solution) | [tests](Tree/tests) | [problem.md](Tree/problem.md) | [validator](Tree/validator) | |
