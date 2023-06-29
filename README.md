# Fire-safety-management-system
```git
⚡ 2023.03 ~ 2023.06
```

&nbsp;&nbsp; <strong>[.NET]소방안전관리시스템</strong>
<br />

&nbsp;&nbsp;⭐ 화재 발생 여부를 모니터링하고, 화재 발생 시 신속한 대처를 할 수 있는 시스템<br />
&nbsp;&nbsp;⭐ select, insert, delete, update, custom query 를 이용하여 5가지 이상의 기능 GUI구현 프로젝트 과제
<br />
<br />

## Using Stacks <br/>
```git
📌 .NET, MSSQL
```
&nbsp;&nbsp;⭐ <strong>ERD & relation table schema</strong> <br />
<div align="center">
      <img src="https://github.com/dahyunko/Fire-safety-management-system/assets/101400650/13cf8b72-1259-45cc-b975-457ab11b21f8" width="600" >
      <p>[ERD]</p></br>
      <img src="https://github.com/dahyunko/Fire-safety-management-system/assets/101400650/29530c9c-36fe-497e-b1ab-e1cf5a86ffaf" width="600" >
      <p>[relation table schema]</p>
</div>

<br />

## ISSUE. 소방대원 신고에 할당하기 <br/>
```git
📌 JOIN + 이중 SELECT
```
&nbsp;&nbsp;⭐ 소방대원 신고에 할당하기<br />
&nbsp;&nbsp;⭐ 화재정보의 규모에 따라 소방대원 명수가 할당된다. <br/>
&nbsp;&nbsp;⭐ 소방대원 명수 = 규모 *2(규모는 1~5로 구분) <br />
</br>
<div align="center">
         <p>   <Strong>SQL: </Strong>SELECT R.rep_id, R.fire_id FROM REPORT AS R WHERE R.scale*2 > <br/>
            (SELECT COUNT(*) FROM FIREFIGHTER AS F WHERE R.rep_id = F.rep_id AND R.fire_id = F.fire_id);
      </p>
      <img src="https://github.com/dahyunko/Fire-safety-management-system/assets/101400650/f6abf86d-4d5e-4abd-9a06-9aedda6aeac5" width="900" >
      <p>[3번 소방대원 신고에 할당]</p>
</div>
  </br>
