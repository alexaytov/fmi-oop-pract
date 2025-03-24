add_executable(main)

# define sources
set(SOURCES
    "main.cpp"
)

SET(ADDITIONAL_SOURCE_FILES
    "functions/functions.cpp"
)

target_sources(
    main
    PRIVATE
    ${SOURCES} ${ADDITIONAL_SOURCE_FILES}
)