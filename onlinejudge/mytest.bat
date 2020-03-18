:again
data > input.txt
assignment2 < input.txt > biaoda_output.txt
test < input.txt > test_output.txt
fc biaoda_output.txt test_output.txt
if not errorlevel 1 goto again
pause