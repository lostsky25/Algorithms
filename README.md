# How to build

```bash
git submodule update --init --recursive
```

```bash
cmake -S . -B build
cmake --build build
```

# How to run tests

```bash
ctest --test-dir build --output-on-failure -j4
```