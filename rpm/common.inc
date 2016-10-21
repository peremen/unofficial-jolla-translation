%define INSTALLDIR %{buildroot}/usr/share

%description
%{summary}

%prep
%setup -q -n %{name}

%build

%install
rm -rf %{INSTALLDIR}
mkdir -p %{INSTALLDIR}/{translations,jolla-supported-languages}
echo $PWD
cp -a usr/share/translations/*-%{QM_SUFFIX}.qm %{INSTALLDIR}/translations/
cp -a usr/share/jolla-supported-languages/%{RPM_SUFFIX}.conf %{INSTALLDIR}/jolla-supported-languages/

%clean
rm -rf ${buildroot}

%files
%{_datadir}/translations/*-%{QM_SUFFIX}.qm
%{_datadir}/jolla-supported-languages/%{RPM_SUFFIX}.conf

%post
localedef --replace -i %{LOCNAME} -f UTF-8 %{LOCNAME}.utf8 --prefix=/

%postun
localedef --delete-from-archive %{LOCNAME}.utf8