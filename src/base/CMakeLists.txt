add_library(base STATIC
    echo.cpp
)

# Create ALIAS targets.
add_library( Echo::base ALIAS base )