# Зв'язаний список

Compile and run:\
```make run```

Check for memory leaks:
```bash
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./list ./books.in
```