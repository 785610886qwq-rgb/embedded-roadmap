# C 的输入输出（对照 C++ 的 cin/cout）

## 一句话对应

| C++ | C |
|---|---|
| `cin >> x;` | `scanf("%d", &x);` |
| `cout << x;` | `printf("%d", x);` |
| `getline(cin, s);` | `fgets(buf, sizeof buf, stdin);` |

C 的两条硬规则：**scanf 要写格式符 + 变量地址**，**printf 只要格式符**。

## scanf 为什么必须加 &

`scanf` 要把读到的值**写进**你的变量，所以它需要知道变量在哪（地址）。C++ 的 `cin >> x` 能自动取地址，是因为它用了引用；C 没有引用，只能你手动 `&x`。

- `int x; scanf("%d", &x);` ✅
- `int x; scanf("%d", x);` ❌ 段错误（把 x 的值当地址用了）

例外：`char buf[100]; scanf("%s", buf);` 不加 `&`——数组名本身就是首地址。

## 格式符对照

| 类型 | scanf | printf |
|---|---|---|
| `int` | `%d` | `%d` |
| `unsigned` | `%u` | `%u` |
| `long` | `%ld` | `%ld` |
| `long long` | `%lld` | `%lld` |
| `float` | `%f` | `%f` |
| `double` | **`%lf`** | `%f`（或 `%lf`，都行） |
| `char` | `%c` | `%c` |
| 字符串 `char[]` | `%s` | `%s` |
| 十六进制 | `%x` | `%x` |
| 保留 2 位小数 | — | `%.2f` |

**最常错**：`double` 用 `scanf` 必须 `%lf`，写成 `%f` 读数会是 0 或乱码。

## 四个必踩的坑

1. **`%c` 读到换行**：上次 `scanf` 留下的 `\n` 会被 `%c` 当字符读走。解决：格式串前加空格 `scanf(" %c", &c);`。
2. **`%s` 遇空格就停**，且不检查长度（缓冲区溢出）。读一行用 `fgets`：
   ```c
   char buf[100];
   fgets(buf, sizeof buf, stdin);
   buf[strcspn(buf, "\n")] = '\0';   // 去掉结尾换行
   ```
3. **返回值**：`scanf` 返回成功读入的项数，失败返回 0，输入结束返回 `EOF`。循环读：
   ```c
   while (scanf("%d", &x) == 1) { ... }
   ```
4. **类型不匹配就卡住**：输入 `abc` 而格式是 `%d`，`x` 不变、`abc` 留在缓冲区，后面的读取全乱。先用返回值判断。

## 对应本周 10 题

```c
// 1. temp.c —— 读 double
double c;
scanf("%lf", &c);

// 5. guess.c —— 循环读整数
int g;
while (scanf("%d", &g) == 1) { ... }

// 6. minmax.c —— 数组循环读
int a[10];
for (int i = 0; i < 10; i++) scanf("%d", &a[i]);

// 10. count.c —— 读一整行
char buf[200];
fgets(buf, sizeof buf, stdin);
```
