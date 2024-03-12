sudo systemctl disable lightdm
sudo systemctl mask lightdm
sudo update-rc.d lightdm disable

sudo systemctl set-default graphical.target
sudo systemctl set-default multi-user.target