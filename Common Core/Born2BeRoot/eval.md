Difference apt vs aptitude && SELinux vs AppArmor

apt vs aptitude
apt is a command-line package management tool used on Debian and Ubuntu systems. It is simple, fast, and commonly used for installing, updating, and removing packages. It’s especially suitable for scripting and quick commands.

aptitude is also a package management tool, but it offers a more user-friendly, menu-based interface in the terminal. Aptitude is great for resolving complex dependency problems, as it can suggest and handle multiple solutions if there are conflicts between packages.

In summary:
apt is faster and more straightforward for everyday use, while aptitude is more powerful for complex package management and troubleshooting.




SELinux vs AppArmor
SELinux (Security Enhanced Linux) is a security module that uses labels and strict, fine-grained rules to control what processes can access on the system. It is extremely flexible and powerful but can be complex to configure. SELinux is commonly used in Red Hat-based distributions like Rocky Linux.

AppArmor is another security module, mainly used in Debian and Ubuntu. It restricts programs based on easy-to-read profiles, making it simpler to use than SELinux, but usually less granular and flexible.

In summary:
SELinux offers more detailed security controls but is harder to manage, while AppArmor is easier to set up and maintain but less flexible.

In short:
You should understand not just how to use these tools, but also when and why to choose one over the other, and what makes them different. This is essential for proving you really know your system during the defense!




SSH requirements in Born2BeRoot

You are required to run an SSH service on port 4242 in your virtual machine.
For security reasons, it must not be possible to log in via SSH as the root user. Only regular user accounts should be allowed to access the system through SSH.

During your defense, your SSH setup will be tested by creating a new user account and connecting to your server using SSH.
Therefore, you must understand how SSH works, how to create users, and how to configure SSH access securely.

In short:

SSH must run on port 4242 (not the default port 22).
Root login via SSH must be disabled.
You need to know how to add new users and test SSH connections as those users.




UFW (Uncomplicated Firewall) Configuration Summary:

You must configure your operating system’s firewall using UFW (for Debian) so that only port 4242 is open on your virtual machine.
This means all other ports must be closed, allowing only SSH connections through port 4242.
The firewall (UFW) must be enabled and active every time you start your virtual machine.

For Rocky Linux, you are required to use firewalld instead of UFW, but the goal is the same: only port 4242 should be open.

In short:

Allow only port 4242 through the firewall.
Make sure the firewall is enabled and running at every boot.
All other ports must be blocked.




Password Policy:
Configuration and Security Requirements:

Set the hostname of your virtual machine to your login name ending with "42" (for example, "wil42").

Be able to change the hostname during your evaluation (defense).

Implement a strong password policy with these rules:

-Passwords must expire every 30 days.

-Users must wait at least 2 days before changing their password again.

-Users get a warning 7 days before their password expires.

-Passwords must be at least 10 characters, and include an uppercase letter, a lowercase letter, and a number.

-No more than 3 identical characters in a row.

-Passwords must not include the user’s name.

-When changing the password (except for root), at least 7 characters must be different from the previous password.

-The root password must also follow the general policy.

-Install and strictly configure sudo according to project requirements.

-Create a regular user with your login as username, in addition to the root user.

-This user must belong to both the user42 group and the sudo group.

During your defense, you must be able to create a new user and assign them to a group.

In short:
You need to set a specific hostname, enforce strict password policies, properly configure sudo, create and manage users and groups, and be ready to demonstrate these tasks live.