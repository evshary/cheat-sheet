# Remote

* Remove remote tag / branch: `git push origin --delete <tag/branch>`
* Delete multiple tag
```bash
git push -d origin $(git tag -l "v*")
git tag -d $(git tag -l "v*")
```

# Clear
* Clear only the ignored files: `git clean -fXd`
* Clear all the untracked files: `git clean -fd`
* Clear all the the untracked and ignored files: `git clean -fxd`
* For git clean, use `-n` to dry run.
* Clean deleted remote branch: `git remote prune origin`

# Submodule
* List all submodules
```bash
git submodule status
```
* Add submodule
```bash
cd <folder>
git submodule add  <repo url>
```
* Get submodule after clone project
```bash
# According to .gitmodules, register the changes into .git/config
git submodule init
# Update submodule according to .git/config
git submodule update
```
* Remove submodule
```bash
rm -rf <submodule repo>
# Modify .gitmodules and remove the related content
vim .gitmodules
# Modify .git/config and remove the related content
vim .git/config
# Add and commit
git add .
git commit 
# Sync the submodule (Update URL according to .gitmodules)
git submodule sync
```

# Bisect
```bash
# stop means the commit with bug, while start means the commit with no bug
git bisect start <stop> <start>
# Decide the commit is good or bad until you find out the bad commit
git bisect good
git bisect bad
# Return origin commit
git bisect reset
```

# Stash
* stash specific file: `git stash push -m your_message <file_name>`

# Patch
## Generate Patch
```bash
# Generate diff file without commit message
git diff <commit N> <commit N+3> --binary > <diff_name>
# Generate patch after commit ID
git format-patch <commit ID>
# Generate 3 patches before commit ID (included)
git format-patch -3 <commit>
# Generate 5 patches before HEAD (included), and put into patch_directory
git format-patch -5 -o <patch_directory>
# Get the patches from commit N to N+3 (not include N)
git format-patch <commit N>..<commit N+3>
```

## Apply patch
```bash
# Check conflict or not
git apply --check <patch_name>
# Apply patch without commit message
git apply <patch_name>
# Apply one patch
git am <patch_name>
# Apply all patches in patch_directory with order
git am <patch_directory>/*
```

# Deploy
* Only clone necessary commit based on branch or tag (For example, v1.0.0)
```bash
git clone -b v1.0.0 --single-branch --depth 1 <URL>
```

# Modify commit date

```bash
# Commit with the specific date
GIT_COMMITTER_DATE="Wed 01 Jun 2022 21:11:16 GMT" git commit --date "Wed 01 Jun 2022 21:11:16 GMT"
# Update the date of last commit
git commit --amend --no-edit --date "Sat 26 Mar 2022 21:45:19 GMT"
GIT_COMMITTER_DATE="Wed 01 Jun 2022 21:11:16 GMT" git commit --amend --no-edit --date "Wed 01 Jun 2022 21:11:16 GMT"
```

# Commit with signoff

```bash
git commit --signoff
# If you also want to modify the author email
git commit --signoff --author="ChenYing Kuo <xxx@yyy.com>"
# If you also want to modify commmiter email
GIT_COMMITTER_EMAIL=xxx@yyy.com git commit --signoff --author="ChenYing Kuo <xxx@yyy.com>"
```

# Undo

* Go back to the last commit and reserve the modification

```bash
git reset HEAD~
# Same as
git reset HEAD~1
```

* Only undo some files

```bash
git reset HEAD~ -- <not_commit_filename>
git commit --amend
```
