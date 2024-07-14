#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void check_write(const char *file_path, const char *value) {
  int fd = open(file_path, O_RDWR);
  if (fd == -1) {
    return;
  }

  char current_value[64];
  ssize_t bytes_read = read(fd, current_value, sizeof(current_value) - 1);
  if (bytes_read >= 0) {
    current_value[bytes_read] = '\0';

    size_t len = strlen(current_value);
    while (len > 0 &&
           (current_value[len - 1] == '\n' || current_value[len - 1] == '\r')) {
      current_value[len - 1] = '\0';
      len--;
    }

    if (strcmp(current_value, value) != 0) {
      lseek(fd, 0, SEEK_SET);
      ftruncate(fd, 0);
      if (write(fd, value, strlen(value)) == -1) {
      }
    }
  } else {
  }

  close(fd);
}

int main() {
  printf("\n");
  printf("Auto Color Tone by RiProG-id\n");
  printf("\n");

  int null_fd = open("/dev/null", O_WRONLY);
  dup2(null_fd, STDOUT_FILENO);
  dup2(null_fd, STDERR_FILENO);
  close(null_fd);

  const char *kcal_1 = "/sys/devices/platform/kcal_ctrl.0";
  char kcal_2[64];
  FILE *fp = NULL;
  int brightness;
  char kcal_r[16];
  char kcal_g[16];
  char kcal_b[16];
  char kcal_rgb[32];
  char kcal_sat[16];
  char kcal_val[16];
  char kcal_cont[16];
  char sat_boost[16];

  struct stat st;
  int kcal_path_exists = 0;

  if (stat(kcal_1, &st) == 0 && S_ISDIR(st.st_mode)) {
    kcal_path_exists = 1;
    check_write("/sys/devices/platform/kcal_ctrl.0/kcal_enable", "1");
  } else if ((fp = popen("find /sys/module/msm_drm/parameters/ -maxdepth 1 "
                         "-type f -name 'kcal_*'",
                         "r")) != NULL) {
    if (fgets(kcal_2, sizeof(kcal_2), fp) != NULL) {
      kcal_path_exists = 2;
      check_write("/sys/module/msm_drm/parameters/kcal_hue", "0");
    }
    pclose(fp);
  } else {
    system("service call SurfaceFlinger 1023 i32 0");
  }

  while (1) {
    fp = popen("settings get system screen_brightness", "r");
    if (fp != NULL) {
      fscanf(fp, "%d", &brightness);
      pclose(fp);

      if (brightness >= 0 && brightness <= 25) {
        strcpy(kcal_r, "240");
        strcpy(kcal_g, "240");
        strcpy(kcal_b, "245");
        snprintf(kcal_rgb, sizeof(kcal_rgb), "%s %s %s", kcal_r, kcal_g,
                 kcal_b);
        strcpy(kcal_sat, "260");
        strcpy(kcal_val, "245");
        strcpy(kcal_cont, "255");
        strcpy(sat_boost, "1.1");
      } else if (brightness >= 26 && brightness <= 50) {
        strcpy(kcal_r, "238");
        strcpy(kcal_g, "239");
        strcpy(kcal_b, "243");
        snprintf(kcal_rgb, sizeof(kcal_rgb), "%s %s %s", kcal_r, kcal_g,
                 kcal_b);
        strcpy(kcal_sat, "265");
        strcpy(kcal_val, "246");
        strcpy(kcal_cont, "257");
        strcpy(sat_boost, "1.2");
      } else if (brightness >= 51 && brightness <= 75) {
        strcpy(kcal_r, "236");
        strcpy(kcal_g, "238");
        strcpy(kcal_b, "241");
        snprintf(kcal_rgb, sizeof(kcal_rgb), "%s %s %s", kcal_r, kcal_g,
                 kcal_b);
        strcpy(kcal_sat, "270");
        strcpy(kcal_val, "248");
        strcpy(kcal_cont, "260");
        strcpy(sat_boost, "1.2");
      } else if (brightness >= 76 && brightness <= 100) {
        strcpy(kcal_r, "234");
        strcpy(kcal_g, "237");
        strcpy(kcal_b, "239");
        snprintf(kcal_rgb, sizeof(kcal_rgb), "%s %s %s", kcal_r, kcal_g,
                 kcal_b);
        strcpy(kcal_sat, "275");
        strcpy(kcal_val, "250");
        strcpy(kcal_cont, "262");
        strcpy(sat_boost, "1.3");
      } else if (brightness >= 101 && brightness <= 125) {
        strcpy(kcal_r, "232");
        strcpy(kcal_g, "236");
        strcpy(kcal_b, "237");
        snprintf(kcal_rgb, sizeof(kcal_rgb), "%s %s %s", kcal_r, kcal_g,
                 kcal_b);
        strcpy(kcal_sat, "280");
        strcpy(kcal_val, "252");
        strcpy(kcal_cont, "265");
        strcpy(sat_boost, "1.3");
      } else if (brightness >= 126 && brightness <= 150) {
        strcpy(kcal_r, "230");
        strcpy(kcal_g, "235");
        strcpy(kcal_b, "235");
        snprintf(kcal_rgb, sizeof(kcal_rgb), "%s %s %s", kcal_r, kcal_g,
                 kcal_b);
        strcpy(kcal_sat, "285");
        strcpy(kcal_val, "254");
        strcpy(kcal_cont, "268");
        strcpy(sat_boost, "1.3");
      } else if (brightness >= 151 && brightness <= 175) {
        strcpy(kcal_r, "228");
        strcpy(kcal_g, "234");
        strcpy(kcal_b, "233");
        snprintf(kcal_rgb, sizeof(kcal_rgb), "%s %s %s", kcal_r, kcal_g,
                 kcal_b);
        strcpy(kcal_sat, "290");
        strcpy(kcal_val, "256");
        strcpy(kcal_cont, "270");
        strcpy(sat_boost, "1.4");
      } else if (brightness >= 176 && brightness <= 200) {
        strcpy(kcal_r, "226");
        strcpy(kcal_g, "233");
        strcpy(kcal_b, "231");
        snprintf(kcal_rgb, sizeof(kcal_rgb), "%s %s %s", kcal_r, kcal_g,
                 kcal_b);
        strcpy(kcal_sat, "295");
        strcpy(kcal_val, "258");
        strcpy(kcal_cont, "273");
        strcpy(sat_boost, "1.4");
      } else if (brightness >= 201 && brightness <= 225) {
        strcpy(kcal_r, "224");
        strcpy(kcal_g, "232");
        strcpy(kcal_b, "229");
        snprintf(kcal_rgb, sizeof(kcal_rgb), "%s %s %s", kcal_r, kcal_g,
                 kcal_b);
        strcpy(kcal_sat, "300");
        strcpy(kcal_val, "260");
        strcpy(kcal_cont, "276");
        strcpy(sat_boost, "1.4");
      } else if (brightness >= 226 && brightness <= 250) {
        strcpy(kcal_r, "222");
        strcpy(kcal_g, "231");
        strcpy(kcal_b, "227");
        snprintf(kcal_rgb, sizeof(kcal_rgb), "%s %s %s", kcal_r, kcal_g,
                 kcal_b);
        strcpy(kcal_sat, "305");
        strcpy(kcal_val, "262");
        strcpy(kcal_cont, "279");
        strcpy(sat_boost, "1.4");
      }

      if (kcal_path_exists == 1) {
        check_write("/sys/devices/platform/kcal_ctrl.0/kcal", kcal_rgb);
        check_write("/sys/devices/platform/kcal_ctrl.0/kcal_sat", kcal_sat);
        check_write("/sys/devices/platform/kcal_ctrl.0/kcal_cont", kcal_cont);
        check_write("/sys/devices/platform/kcal_ctrl.0/kcal_val", kcal_val);
      } else if (kcal_path_exists == 2) {
        check_write("/sys/module/msm_drm/parameters/kcal_red", kcal_r);
        check_write("/sys/module/msm_drm/parameters/kcal_green", kcal_g);
        check_write("/sys/module/msm_drm/parameters/kcal_blue", kcal_b);
        check_write("/sys/module/msm_drm/parameters/kcal_cont", kcal_cont);
        check_write("/sys/module/msm_drm/parameters/kcal_sat", kcal_sat);
        check_write("/sys/module/msm_drm/parameters/kcal_val", kcal_val);
      } else {
        char cmd[64];
        snprintf(cmd, sizeof(cmd), "service call SurfaceFlinger 1022 f %s",
                 sat_boost);
        system(cmd);
      }
    }

    sleep(2);
  }

  return 0;
}