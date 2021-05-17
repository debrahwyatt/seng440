call git fetch
call git pull
call git merge
echo.

call git add .
call git commit -m %1
call git push
echo.