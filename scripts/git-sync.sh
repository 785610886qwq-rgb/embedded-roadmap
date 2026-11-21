#!/bin/bash
# 日常提交脚本：git add 全部 → 有改动才 commit → push
# 用法：bash scripts/git-sync.sh "feat(w1): 完成变量与运算符练习"
set -e

msg="${1:-chore: update}"

cd "$(git rev-parse --show-toplevel)"

git add -A

if git diff --cached --quiet; then
    echo "没有改动，跳过提交"
    exit 0
fi

git commit -m "$msg"
git push
