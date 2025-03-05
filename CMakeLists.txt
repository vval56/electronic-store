cmake_minimum_required(VERSION 3.10)
project(MyGTKApp LANGUAGES C)

# Найти GTK3
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Найти SQLite3
find_package(PkgConfig REQUIRED)
pkg_check_modules(SQLite3 REQUIRED sqlite3)

if(NOT SQLite3_FOUND)
    message(FATAL_ERROR "SQLite3 not found. Please install libsqlite3-dev.")
endif()

# Включение заголовочных файлов GTK3 и SQLite3
include_directories(${GTK3_INCLUDE_DIRS} ${SQLite3_INCLUDE_DIRS})

# Указание всех исходных файлов проекта
set(SOURCES
    src/main.c
    src/windows/main-w.c
    src/windows/login-w.c
    src/windows/databasel/databasel.c
    src/windows/admin-w.c
)

# Создание исполняемого файла
add_executable(mygtkapp ${SOURCES})

# Скомпоновать с GTK3 и SQLite3
target_link_libraries(mygtkapp PRIVATE
    ${GTK3_LIBRARIES}
    ${SQLite3_LIBRARIES}
)

# Добавление директорий с заголовочными файлами
target_include_directories(mygtkapp PRIVATE
    ${CMAKE_SOURCE_DIR}/headers
    ${CMAKE_SOURCE_DIR}/databasel
)

# Если нужно скопировать SQL-скрипт
configure_file(
    "${CMAKE_SOURCE_DIR}/sql/data-l.sql"
    "${CMAKE_BINARY_DIR}/data-l.sql"
    COPYONLY
)
