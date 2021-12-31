read main brute
for((i = 1; ; ++i)); do
    echo $i
    ./generator_test $i > inp
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(./$main < inp) <(./$brute < inp) || break
done
