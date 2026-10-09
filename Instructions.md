# Working with GitHub

## 1. Installing Fork and Logging In

**1.1 Install Fork**

Download and install the [Fork application](https://git-fork.com/) on your computer.

**1.2 Add Your GitHub Account to Fork**

1. Open Fork.
2. Go to the menu **File > Accounts**.
3. Press the **`+`** button at the bottom of the window.
4. Select **GitHub.com** and log in with your GitHub credentials.
5. Fork opens a browser where you can accept the application's permissions.

> **Why?** Once Fork is connected to your GitHub account, it handles authentication automatically. You don't need to create SSH keys or enter your password every time.

---

## 2. Cloning a Repository

**2.1 Copy the Repository URL**

1. Go to the page of the repository you want on GitHub.
2. Press the green **`<> Code`** button.
3. Make sure the **HTTPS** tab is selected.
4. Copy the URL. It is in the format:  
   `https://github.com/username/repository.git`

> If you don't have an SSH key created, always use the HTTPS version.

**2.2 Clone in Fork**

1. Open Fork (if you haven't already).
2. Go to the menu **File > Clone** or press **`CTRL + N`** (Windows) / **`CMD + N`** (Mac).
3. Paste the URL you copied into the appropriate field.
4. Select the **Parent Folder**, i.e., the folder where the repository will be downloaded.
5. Press **"Test Connection"** to make sure the connection to GitHub works.
6. Press **"Clone"**.

> If cloning fails, the most common reason is that Fork cannot write to the folder you selected. Change the destination folder and try again.

---

## 3. Creating a New Branch

> A branch is like a "parallel universe" for code. By working in your own branch, you can make changes without breaking the functionality of the main version (`main`).

**3.1 Check That You Are in the Right Branch**

1. In Fork's left column, you can see **Branches** and **Remotes**.
2. Open the **Branches** menu. The `main` branch should be selected.
3. When you click the `main` branch, in the view on the right you will see all the commits made to that branch and their authors.

**3.2 Create a New Branch**

1. **Right-click** the `main` branch in the left column.
2. Select **"New Branch"**.
3. Give the branch a descriptive name, for example:
   - `update-readme` (you are updating the README file)
   - `refactor-code` (improving/cleaning up the code)
   - `add-new-feature` (you are adding a new feature)
4. If you want to switch to the new branch automatically, make sure **"Check out after create"** is selected.
5. Press **"Create Branch"**.

> **Important:** When you work in a new branch, all the changes you make appear _only in this branch_. The `main` branch remains unchanged.

---

## 4. Editing Code

**4.1 Open the Code in Your Own IDE**

1. Open the code editor of your choice (e.g., VS Code).
2. Open the cloned repository in the editor.
3. If you created a new branch, VS Code shows at the bottom which branch you are on (e.g., `update-readme`).

**4.2 Make Changes**

- Edit, add, or delete files as needed.
- Save the changes by pressing **`CTRL + S`** (Windows) / **`CMD + S`** (Mac).

---

## 5. Saving and Sending Changes

Once you are satisfied with the changes you have made, it is time to save them to Git's version control and send them to GitHub.

**5.1 Save the Changes**

1. Go back to the Fork application.
2. In the left column, you will see **"Local Changes"** and below it a list of the changed files.
3. Select which files you want to include in the next save by clicking the file and then the **`Stage`** button above the files. The file moves to the "Staged" area.

**5.2 Make a Commit (Save to the Change History)**

1. Write a **commit message**.
2. A good commit message tells _what_ you changed, not _how_. For example:
   - feat: added resetting functionality
   - fix: corrected broken link
   - refactor: simplified logic
3. Press **"Commit"**.

**5.3 Push the Changes to GitHub**

1. Press the **"Push"** button.
2. The changes are sent to _your own_ GitHub repository (your fork).

> **NOTE.** If multiple people are working on the code at the same time, you should always start your coding session by fetching the latest changes from GitHub. This is done using the **Fetch** and **Pull** options. Fetch checks whether there are new changes in the repo, and Pull checks and downloads the new changes to your device.

---

## 6. Reviewing and Merging Changes

After pushing, the changes appear on GitHub, but they are not yet part of the main code. Before the changes are merged, they can be reviewed and tested to ensure they don't cause problems with the rest of the code. GitHub indicates which files and lines are in conflict. Once they have been fixed and the changes approved, the new code is merged into the main branch.