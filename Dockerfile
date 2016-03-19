FROM lukasheinrich/andrew-base
ENV ROOTSYS /usr/local
RUN git clone --quiet http://root.cern.ch/git/root.git /code/root-v5-34-09 && \
    cd  /code/root-v5-34-09 && \
    git checkout v5-34-09 && \
    ./configure --all && \
    make -j4 && \
    make install && \
    cd / && rm -rf /code/root-v5-34-09
ADD . /code/56_Hbbyy
RUN source /usr/local/bin/thisroot.sh && cd /code/56_Hbbyy && \
    make bin/DHMaster && \
    make bin/DHPseudoExp && \
    make bin/DHCLScan && \
    make bin/DHNuisanceParameters && \
    make bin/DHPlotCLvsMX && \
    make bin/DHNLLScan
    
