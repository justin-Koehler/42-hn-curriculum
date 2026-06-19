find . -type f -name "*.sh" | sed 's|./||' | xargs -I {} basename {} .sh
