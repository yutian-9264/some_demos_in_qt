QTextStream out;
QFile *paramfile;

QDir *firstDir = new QDir;
QDateTime datetime;
QString timestr = datetime.currentDateTime().toString("yyyy_MMdd_HHmm_ss");
QString day = datetime.currentDateTime().toString("yyyy_MMdd");

if (!firstDir->exists("./log/data_saved/" + day)){
    firstDir->mkpath("./log/data_saved/" + day);
}
QString File_path = "./log/data_saved/" + day + "/" + "T" + timestr + ".txt";
paramfile = new QFile(File_path);
paramfile->open(QIODevice::ReadWrite);

out.setDevice(paramfile);
out << "%imu param"
    << "\n";

for (int i = 0; i < imu_retest_param_data_new.len / 4; i++){
    out << i << "," << p_imu_calib[i] << "\n";
}

paramfile->close();