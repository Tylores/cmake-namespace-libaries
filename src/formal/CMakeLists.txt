add_library(formal STATIC
    formal_echo.cpp
)

# Create ALIAS targets.
add_library( Echo::formal ALIAS formal )