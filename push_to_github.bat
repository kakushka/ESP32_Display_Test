@echo off
echo Синхронизация локального проекта на GitHub...
git add .
git commit -m "Автоматический коммит"
git push origin main
echo Готово!
pause
