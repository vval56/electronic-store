cmake_minimum_required(VERSION 3.10)
project(MyGtkApp)

# Поиск GTK 3.x
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Настройка компиляции
include_directories(${GTK3_INCLUDE_DIRS})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GTK3_CFLAGS_OTHER}")

# Добавление исполняемого файла
add_executable(mygtkapp src/main.c src/database-product/database-prod.c)

# Линковка GTK
target_link_libraries(mygtkapp ${GTK3_LIBRARIES})
